#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "solve.h"
#include "data.h"
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


	printf("Hello Lesolve!\n");
	app_init();
    
	printf("Goodbye Lesolve!\n");
}

void app_init() {
    double local_system[RANGE][RANGE];

    double *system_ptr[RANGE];
    for (uint64_t i = 0; i < RANGE; i++) {
        system_ptr[i] = local_system[i];
    }

    // print_system(system_ptr, right, RANGE);
    for (unsigned long i = 0; i < 150; i++) {
        for (unsigned long x = 0; x < RANGE; x++) {
            for (unsigned long y = 0; y < RANGE; y++) {
                local_system[x][y] = system[x][y];
            }
        }

        if(i%10)
            printf("%d Percent done \n", (i*100)/150);
        solve_system(system_ptr, right, RANGE);
    }

    // print_system(system_ptr, right, RANGE);
}

