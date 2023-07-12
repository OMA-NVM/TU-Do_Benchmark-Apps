#ifndef __MEMORY_ALLOCATOR__
#define __MEMORY_ALLOCATOR__

#include <stddef.h>

// Problem: Local variables are pushed onto app_stack instead of OS_stack.

void* app_malloc(size_t size);
void app_free(void* addr);

#endif