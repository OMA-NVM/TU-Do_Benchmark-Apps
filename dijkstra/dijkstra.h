#define NUM_NODES 100
#define NONE 9999
#include "struct.h"

// START DIJKSTRA
void dijkstra(long chStart, long chEnd) {
  for (ch = 0; ch < NUM_NODES; ch++) {
    rgnNodes[ch].iDist = NONE;
    rgnNodes[ch].iPrev = NONE;
  }

  if (chStart == chEnd) {
    printf("Shortest path is 0 in cost. Just stay where you are.\n");
  } else {
    rgnNodes[chStart].iDist = 0;
    rgnNodes[chStart].iPrev = NONE;

    enqueue(chStart, 0, NONE);

    while (qcount() > 0) {
      dequeue(&iNode, &iDist, &iPrev);
      for (i = 0; i < NUM_NODES; i++) {
        if ((iCost = AdjMatrix[iNode][i]) != NONE) {
          if ((NONE == rgnNodes[i].iDist) ||
              (rgnNodes[i].iDist > (iCost + iDist))) {
            rgnNodes[i].iDist = iDist + iCost;
            rgnNodes[i].iPrev = iNode;
            enqueue(i, iDist + iCost, iNode);
          }
        }
      }
    }

    printf("Shortest path is %d  in cost.\n", rgnNodes[chEnd].iDist);
    printf("Path is: \n");
    print_path(rgnNodes, chEnd);
    printf("\n");
  }
}

void run_disjkstra() {
  // printf("Switched stack\n");
  long i, j;

  /* make a fully connected matrix */
   for (i = 0; i < NUM_NODES; i++) {
      for (j = 0; j < NUM_NODES; j++) {
       /* make it more sparce */
       // printf("Sanity Check: %d, %d \n", sanity, *rot_cnt);
       AdjMatrix[i][j] = dijkstra_input_data[i][j];
      }
   }

  /* finds 10 shortest paths between nodes */
  for (i = 0, j = NUM_NODES / 2; i < 100; i++, j++) {
    j = j % NUM_NODES;
    // printf("Sanity Check: %d, %d \n", sanity, *rot_cnt);
    dijkstra(i, j);
  }
}

void print_dijkstra() {
  for (int i = 0; i < 100; i++) {
    printf("Data @ %d : %d\n", i, (int)dijkstra_input_data[i][0]);
  }
}

// END DIJKSTRA


void dijkstra_data(long chStart, long chEnd) {
  for (ch = 0; ch < NUM_NODES; ch++) {
    rgnNodes_data[ch].iDist = NONE;
    rgnNodes_data[ch].iPrev = NONE;
  }

  if (chStart == chEnd) {
    printf("Shortest path is 0 in cost. Just stay where you are.\n");
  } else {
    rgnNodes_data[chStart].iDist = 0;
    rgnNodes_data[chStart].iPrev = NONE;

    enqueue(chStart, 0, NONE);

    while (qcount() > 0) {
      dequeue(&iNode, &iDist, &iPrev);
      for (i = 0; i < NUM_NODES; i++) {
        if ((iCost = AdjMatrix_data[iNode][i]) != NONE) {
          if ((NONE == rgnNodes_data[i].iDist) ||
              (rgnNodes_data[i].iDist > (iCost + iDist))) {
            rgnNodes_data[i].iDist = iDist + iCost;
            rgnNodes_data[i].iPrev = iNode;
            enqueue(i, iDist + iCost, iNode);
          }
        }
      }
    }

    printf("Shortest path is %d  in cost.\n", rgnNodes_data[chEnd].iDist);
    printf("Path is: \n");
    print_path(rgnNodes_data, chEnd);
    printf("\n");
  }
}

void run_disjkstra_data() {
  // printf("Switched stack\n");
  long i, j;

  /* make a fully connected matrix */
   for (i = 0; i < NUM_NODES; i++) {
      for (j = 0; j < NUM_NODES; j++) {
       /* make it more sparce */
       // printf("Sanity Check: %d, %d \n", sanity, *rot_cnt);
       AdjMatrix_data[i][j] = dijkstra_input_data[i][j];
      }
   }

  /* finds 10 shortest paths between nodes */
  for (i = 0, j = NUM_NODES / 2; i < 100; i++, j++) {
    j = j % NUM_NODES;
    // printf("Sanity Check: %d, %d \n", sanity, *rot_cnt);
    dijkstra_data(i, j);
  }
}

void dijkstra_heap(long chStart, long chEnd) {
  for (ch = 0; ch < NUM_NODES; ch++) {
    rgnNodes[ch].iDist = NONE;
    rgnNodes[ch].iPrev = NONE;
  }

  if (chStart == chEnd) {
    printf("Shortest path is 0 in cost. Just stay where you are.\n");
  } else {
    rgnNodes[chStart].iDist = 0;
    rgnNodes[chStart].iPrev = NONE;

    enqueue(chStart, 0, NONE);

    while (qcount() > 0) {
      dequeue(&iNode, &iDist, &iPrev);
      for (i = 0; i < NUM_NODES; i++) {
        if ((iCost = AdjMatrix[iNode][i]) != NONE) {
          if ((NONE == rgnNodes[i].iDist) ||
              (rgnNodes[i].iDist > (iCost + iDist))) {
            rgnNodes[i].iDist = iDist + iCost;
            rgnNodes[i].iPrev = iNode;
            enqueue(i, iDist + iCost, iNode);
          }
        }
      }
    }

    printf("Shortest path is %d  in cost.\n", rgnNodes[chEnd].iDist);
    printf("Path is: \n");
    print_path(rgnNodes, chEnd);
    printf("\n");
  }
}

void run_dijkstra_heap() {
  long r, c = 100;
  long i, j;

  printf("start allocating heap\n");
  long* arr[r]; 
  for (i = 0; i < r; i++) {
	  arr[i] = (long*)malloc(c* sizeof(long));
  }
  if (arr==NULL)
  {
    printf("failed");
  }
  
  printf("finished allocating heap and start getting input\n");
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      arr[i][j] = dijkstra_input_data[i][j];
    }	
  }

   for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) { 
            printf("%d ", arr[i][j]);
        }
  }
  //   // printf("Switched stack\n");

  // printf("got input now copying to Adjmatrix\n");
  // /* make a fully connected matrix */
  //  for (i = 0; i < NUM_NODES; i++) {
  //     for (j = 0; j < NUM_NODES; j++) {
  //      /* make it more sparce */
  //      // printf("Sanity Check: %d, %d \n", sanity, *rot_cnt);
  //      AdjMatrix[i][j] = arr[i][j];
  //     }
  //  }
  // printf("copying to Adjmatrix done\n");
  // /* finds 10 shortest paths between nodes */
  // for (i = 0, j = NUM_NODES / 2; i < 100; i++, j++) {
  //   j = j % NUM_NODES;
  //   // printf("Sanity Check: %d, %d \n", sanity, *rot_cnt);
  //   dijkstra_heap(i, j);
  // }
  
  printf("free allocated space");
  for (int i = 0; i < r; i++) {
      free(arr[i]);
  }
}
