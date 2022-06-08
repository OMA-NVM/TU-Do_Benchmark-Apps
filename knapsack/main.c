#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "knapsack.h"

int main(int argc, char *argv[])
{


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