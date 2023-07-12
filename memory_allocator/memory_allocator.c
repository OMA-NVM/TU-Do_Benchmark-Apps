#include "memory_allocator.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

#define SIZE 50000

static char memory[SIZE] __attribute__ ((section(".appheap")));

struct HeapBlock{
    size_t size;
    int free;
    struct HeapBlock* previous;
    struct HeapBlock* next;
};

typedef struct HeapBlock HeapBlock;

HeapBlock* heap = (HeapBlock*) memory;

void Init() {
    heap->size = SIZE - sizeof(HeapBlock);
    heap->free = 1;
    heap->previous = NULL;
    heap->next = NULL;
}

void Split(HeapBlock* block, size_t size) {
    HeapBlock* left = block;
    HeapBlock* right = (void*)block + size + sizeof(HeapBlock);

    right->size = block->size - size - sizeof(HeapBlock);
    right->next = block->next;
    right->previous = left;

    left->size = size;
    left->next = right;
    left->previous = block->previous;
}

void Take(HeapBlock* freeBlock, size_t size) {
    if(freeBlock->size < size) {
        assert(0);
    }

    if(freeBlock->size > size) {
        Split(freeBlock, size);
    }
    
    freeBlock->free = 0;
}

HeapBlock* FindNextFit(size_t size) {
    HeapBlock* current = heap;

    while(current != NULL) {
        if(current->free && current->size >= size) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void Merge(HeapBlock* left, HeapBlock* right) {
    if(left == NULL || right == NULL) {
        return;
    }

    left->size = left->size + right->size + sizeof(HeapBlock);
    left->next = right->next;
}

void MergeAll() {
    HeapBlock* current = heap;
    HeapBlock* next = current->next;

    if(next == NULL) {
        return;
    }

    while(next != NULL) {
        if(current->free && next->free) {
            Merge(current, next);
            next = current->next;
        } else {
            current = next;
            next = current->next;
        }
    }
}

int WasAllocated(HeapBlock* block) {
    HeapBlock* current = heap;

    while(current != NULL) {
        if(!current->free && current == block) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

void* app_malloc(size_t size) {
    if(!heap->size) {
        Init();
    }
    
    HeapBlock* fitting = FindNextFit(size);

    if(fitting == NULL) {
        return NULL;
    }

    Take(fitting, size);

    return ++fitting;
}

void* app_realloc(void* addr, size_t size) {
    if(addr == NULL) {
        return app_malloc(size);
    }

    if(size == 0) {
        // Implementation defined behaviour according to C specification.
        // Our decision: Nothing happens, return NULL.
        return NULL;
    }

    HeapBlock* block = addr;
    block--;

    if(!WasAllocated(block)) {
        // Undefined behaviour according to C specification.
        return NULL;
    }

    if(block->size == size) {
        return addr;
    }

    if(block->size > size) {
        Split(block, size);
        block->next->free = 1;
        MergeAll();
        return addr;
    }

    if(block->size < size) {
        // First try to expand
        if(block->next != NULL && block->next->free && block->size + block->next->size + sizeof(HeapBlock) <= size) {
            Merge(block, block->next);
            return addr;
        }

        // Second try to find alternative place
        void* alternativeBlock = app_malloc(size);
        if(alternativeBlock == NULL) {
            // Do not free memory.
            return NULL;
        }

        memcpy(alternativeBlock, addr, block->size);
        app_free(addr);
        return alternativeBlock;
    }
}

void app_free(void* addr) {
    HeapBlock* occupied = addr;
    occupied--;

    if(!((void*)occupied >= (void*)memory && (void*)occupied < (void*)(memory + SIZE))) {
        // Address is not part of the heap.
        return;
    }

    occupied->free = 1;
    MergeAll();
}