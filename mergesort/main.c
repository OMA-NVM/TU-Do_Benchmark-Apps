#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "mergesort.c"
#include "input.h"
#include "../regions_header/mem_regions.h"
#define DATA 0
#define BSS 0
#define HEAP 1
#define STACK 0



int main(int argc, char *argv[])
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
      arr[i] = (int*)malloc(sizeof(int));
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
      free(arr[i]);
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
