#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */

#include "data.h"
#include "includes.h"
#include "qsort.h"


int main(int argc, char *argv[])
{
	printf("Hello qsort!\n");

	app_init();
	printf("Qsort ende!\n");
	printf("Aufgeräumt!\n");

}
