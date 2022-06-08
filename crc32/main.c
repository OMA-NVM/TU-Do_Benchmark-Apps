#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */
#include "crc_32.h"
#include "crc.h"

int main(int argc, char *argv[])
{


	printf("Hello crc32!\n");
	app_init();
	
	printf("Ende crc32!\n");
}


void app_init() {
    DWORD crc;
    long charcnt;

    printf("Doing CRC\n");

    crc32file(&crc, &charcnt);
    printf("%08lX %7ld\n", crc, charcnt);
}