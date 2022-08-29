#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "sha.h"
#include "../regions_header/mem_regions.h"

unsigned long __apptext_start;
unsigned long __apptext_end;
unsigned long __approdata_start;
unsigned long __approdata_end;
unsigned long __appdata_start;
unsigned long __appdata_end;
unsigned long __appbss_start;
unsigned long __appbss_end;
unsigned long __appstack_start;
unsigned long __appstack_end;
unsigned long __appheap_start;
unsigned long __appheap_end;

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
    
	printf("Hello sha!\n");
	app_init();
	printf("Goodbye sha!\n");

}


void app_init() {
    printf("Going to apply sha\n");
    unsigned long test = (unsigned long)sha_stream;
    // printf("Test PTR is at 0x%lx\n", test);
    for (unsigned long i = 0; i < 3; i++) {
        SHA_INFO sha_info;

        sha_stream(&sha_info, sha_input_large);
        sha_print(&sha_info);
    }

     //printf("Test PTR is at 0x%lx\n", test);

     printf("Exiting\n");
}