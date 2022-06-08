#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "aesxam.h"

int main(int argc, char *argv[])
{

	printf("Hello rijndael!\n");
	app_init();
	printf("Ende rijndael!\n");
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