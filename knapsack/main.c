#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "knapsack.h"
#include "../regions_header/mem_regions.h"

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

	printf("Hello Knapsack!\n");
	app_init();
	printf("Ende Knapsack!\n");

}

// Driver program to test above function
int app_init() {
  //https://people.sc.fsu.edu/~jburkardt/datasets/knapsack_01/knapsack_01.html
    int val[] = { 70,
                  20,
                  39,
                  37,
                   7,
                   5,
                  10,
                };
    int wt[] = { 31,
                  10,
                  20,
                  19,
                   4,
                   3,
                   6,
                };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Calculated: %d\n", knapSack(W, wt, val, n));
    printf("Correct: %d\n", 13549094);
    return 0;
}