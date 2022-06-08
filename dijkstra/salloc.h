#pragma once

#define SIMPLE_ALLOC_SIZE 16384

#define NULL 0

void *s_malloc(unsigned long size);

void s_free(void *mem);

volatile unsigned int sanity = 512;

volatile unsigned long dataStart;
volatile unsigned long dataEnd;

char alloc_pool[SIMPLE_ALLOC_SIZE];
char *alloc_ptr = alloc_pool;

void *s_malloc(unsigned long size) {
  char *copy = alloc_ptr;
  alloc_ptr += size;
  if (alloc_ptr >= alloc_pool + SIMPLE_ALLOC_SIZE) {
    // Wraparound alloc
    alloc_ptr = alloc_pool + size;
    return alloc_pool;
  }
  return copy;
}

void s_free(void *mem) {}