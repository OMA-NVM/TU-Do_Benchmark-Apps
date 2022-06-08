#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "data.h"
#include "qsort_b.h"

int main(int argc, char *argv[])
{


	printf("Hello qsort_b!\n");
	app_init();
	printf("Goodbye qsort_b!\n");
}


void app_init() {
    unsigned long sort_size = 8000;

    // quick_sort_f(random_number, random_number + sort_size);

    for (unsigned long i = 0; i < 5; i++) {
        for (unsigned long x = 0; x < sort_size; x++) {
            sort_buffer[x] = random_number[x];
        }
        quick_sort_f(sort_buffer, sort_buffer + sort_size);

        for (unsigned long x = 0; x < sort_size; x++) {
            sort_buffer[x] = random_number[x];
        }
        quick_sort_b(sort_buffer, sort_buffer + sort_size);
    }
}