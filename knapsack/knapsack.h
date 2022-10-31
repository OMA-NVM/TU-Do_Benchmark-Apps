/* A Naive recursive implementation
of 0-1 Knapsack problem */
#include <stdio.h>
#include "input.h"

unsigned int RecursionCounter = 0;
// A utility function that returns
// maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that
// can be put in a knapsack of capacity W

int i, w;
int K[200 + 1][200 + 1];

int knapSack(int W, int wt[], int val[], int n) {
  printf("Recursion#: %d\n", RecursionCounter++);
 
    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
      printf("Iteration: %d of recursion: %d", i, RecursionCounter);
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                          + K[i - 1][w - wt[i - 1]],
                          K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
    return K[n][W];
}
// END knapsack

// Driver program to test above function
int size=200;
int values[];
int weight[];


int app_init() {
  //https://people.sc.fsu.edu/~jburkardt/datasets/knapsack_01/knapsack_01.html
  for (int i = 0; i < size; i++)
  {
    values[i] = val[i];
    weight[i] = wt[i];
  }
  
  int W = 200;
  int n = sizeof(val) / sizeof(values[0]);
  printf("Calculated: %d\n", knapSack(W, weight, values, n));
  printf("Correct: %d\n", 13549094);
  return 0;
}
