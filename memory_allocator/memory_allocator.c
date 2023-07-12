#include "memory_allocator.h"

#include <assert.h>
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

void Split(HeapBlock* freeBlock, size_t size) {
    HeapBlock* left = freeBlock;
    HeapBlock* right = (void*)freeBlock + size + sizeof(HeapBlock);

    right->size = freeBlock->size - size - sizeof(HeapBlock);
    right->next = freeBlock->next;
    right->previous = left;

    left->size = size;
    left->next = right;
    left->previous = freeBlock->previous;
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
        printf("-----\n");
        printf("Current free: %u\n", current->free);
        printf("Current size: %u\n", current->size);

        if(current->free && current->size >= size) {
            return current;
        }

        current = current->next;
    }

    printf("Found no fit!\n");

    return NULL;
}

void Merge(HeapBlock* left, HeapBlock* right) {
    if(left == NULL || right == NULL) {
        return;
    }

    if(left->free == 0 || right->free == 0) {
        assert(0);
        // TODO: Correct error handling.
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

void* app_malloc(size_t size) {
    if(!heap->size) {
        Init();
    }
    
    HeapBlock* fitting = FindNextFit(size);
    printf("Next fitting: %x", fitting);

    if(fitting == NULL) {
        return NULL;
    }

    Take(fitting, size);

    return ++fitting;
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