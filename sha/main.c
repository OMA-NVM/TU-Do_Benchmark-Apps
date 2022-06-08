#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "sha.h"

int main(int argc, char *argv[])
{


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