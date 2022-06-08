#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */


//Input array, malloc and dijkstra headers
#include "input.h"
#include "salloc.h"
#include "dijkstra.h"



int main(int argc, char *argv[])
{


	printf("Hello dijkstra!\n");

	run_disjkstra();
  	printf("Ende dijkstra!\n");
  	printf("Ganz Aufgeräumt!\n");

}
