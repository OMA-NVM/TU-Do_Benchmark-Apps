#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "solve.h"
#include "../../libs/regions_header/mem_regions.h"
#define DATA 0
#define BSS 0
#define HEAP 0
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

    #elif !DATA && BSS && !HEAP && STACK

    #else
	printf("Hello Lesolve!\n");
    app_init();
	printf("Goodbye Lesolve!\n");
    #endif
}
