#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "aesxam.h"
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

	printf("Hello rijndael!\n");
	app_init();
	printf("Ende rijndael!\n");
    #endif
}


void app_init() {
    for (unsigned int x = 0; x < 1; x++) {
        input_read_ptr = 0;
        input_write_ptr = 0;
        char *cp =
            "1234567890abcdeffedcba09876543211234567890abcdeffedcba098765432"
            "1"; /* this is a pointer to the hexadecimal key digits  */
        char *ch;
        unsigned int i =
            0; /* this is a count for the input digits processed   */

        aes ctx[1];

        printf("Starting file encryption\n");

        encfile(ctx);

        printf("Finish encryption\n");
    }
}
