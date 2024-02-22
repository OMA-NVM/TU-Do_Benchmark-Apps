#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "mergesort.c"
#include "input.h"
#include "../mem_regions.h"
#include "../memory_allocator/memory_allocator.h"
#include "../work_around.h"
#define DATA 0
#define BSS 0
#define HEAP 1
#define STACK 0

int mainApp(int argc, char *argv[]);

// In order to seperate app stack from os stack within unikraft.
int main(int argc, char *argv[]) {
	unsigned long osSP;
	unsigned long correctedAppStackEnd = (unsigned long)(&__appstack_end) - 8; // Because __appstack_end address should be exclusive.

	asm volatile (
		"stp x0,x1,[sp,#-16]!;"
        "stp x2,x3,[sp,#-16]!;"
        "stp x4,x5,[sp,#-16]!;"
        "stp x6,x7,[sp,#-16]!;"
        "stp x8,x9,[sp,#-16]!;"
        "stp x10,x11,[sp,#-16]!;"
        "stp x12,x13,[sp,#-16]!;"
        "stp x14,x15,[sp,#-16]!;"
        "stp x16,x17,[sp,#-16]!;"
        "stp x18,x30,[sp,#-16]!;"
        ""
		"mov x0, sp;"
		"str x0, [%2];"
		"mov sp, %0;"
		"blr %1;"
		""
        "ldr x0, [%2];"
        "mov sp, x0;"
        ""
        "ldp x18,x30,[sp],#16;"
        "ldp x16,x17,[sp],#16;"
        "ldp x14,x15,[sp],#16;"
        "ldp x12,x13,[sp],#16;"
        "ldp x10,x11,[sp],#16;"
        "ldp x8,x9,[sp],#16;"
        "ldp x6,x7,[sp],#16;"
        "ldp x4,x5,[sp],#16;"
        "ldp x2,x3,[sp],#16;"
        "ldp x0,x1,[sp],#16;" :: "r"(correctedAppStackEnd), "r"(mainApp), "r"(&osSP) : "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x30"
	);
}

int mainApp(int argc, char *argv[])
{
	printf("__apptext_start: 0x%lx\n", &__apptext_start);
	printf("__apptext_end: 0x%lx\n", &__apptext_end);
	printf("__approdata_start: 0x%lx\n", &__approdata_start);
	printf("__approdata_end: 0x%lx\n", &__approdata_end);
	printf("__appdata_start: 0x%lx\n", &__appdata_start);
	printf("__appdata_end: 0x%lx\n", &__appdata_end);
	printf("__appbss_start: 0x%lx\n", &__appbss_start);
	printf("__appbss_end: 0x%lx\n", &__appbss_end);
	printf("__appheap_start: 0x%lx\n", &__appheap_start);
	printf("__appheap_end: 0x%lx\n", &__appheap_end);
	printf("__appstack_start: 0x%lx\n", &__appstack_start);
	printf("__appstack_end: 0x%lx\n", &__appstack_end);

  	#if DATA && !BSS && !HEAP && !STACK

    #elif !DATA && BSS && !HEAP && !STACK

    #elif !DATA && !BSS && HEAP && !STACK


  printf("start allocating heap\n");
    int* arr[1000];
    for (int i = 0; i < 1000; i++) {
      arr[i] = (int*)app_malloc(sizeof(int));
    }
    if (arr==NULL)
    {
      printf("failed");
    }

    printf("finished allocating heap and start getting input\n");
    for (int i = 0; i < 1000; i++) {
        arr[i] = input[i];
    }
    printf("free allocated space");
    for (int i = 0; i < 1000; i++) {
      app_free(arr[i]);
    }

    #elif !DATA && BSS && !HEAP && STACK

    #else

	printf("Hello Mergesort!\n");
  int array[LENGTH];
  for (int i = 0; i < LENGTH; i++)
  {
    array[i] = input[i];
  }

  mergeSort(array, LENGTH);
  printArray(array, LENGTH);
  printf("test");
  #endif
  printf("Goodbye !\n");

}
