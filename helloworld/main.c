#include <stdio.h>
#include "../mem_regions.h"

#include "../work_around.h"

/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */

#if CONFIG_APPHELLOWORLD_SPINNER
#include <time.h>
#include <errno.h>
#include "monkey.h"

static void millisleep(unsigned int millisec)
{
	struct timespec ts;
	int ret;

	ts.tv_sec = millisec / 1000;
	ts.tv_nsec = (millisec % 1000) * 1000000;
	do
		ret = nanosleep(&ts, &ts);
	while (ret && errno == EINTR);
}
#endif /* CONFIG_APPHELLOWORLD_SPINNER */

int mainApp(int argc, char *argv[]);

// In order to seperate app stack from os stack within unikraft.
int main(int argc, char *argv[]) {
	unsigned long osSP;
	unsigned long correctedAppStackEnd = (unsigned long)(&__appstack_end) - 8; // Because __appstack_end address should be exclusive.

	asm volatile (
		"stp x0,x1,[sp,#-16]!;"
        "stp x2,x3,[sp,#-16]!;"
        "stp x4,x5,[sp,#-16]!;"
        "stp x6,x7,[sp,#-16]!;"
        "stp x8,x9,[sp,#-16]!;"
        "stp x10,x11,[sp,#-16]!;"
        "stp x12,x13,[sp,#-16]!;"
        "stp x14,x15,[sp,#-16]!;"
        "stp x16,x17,[sp,#-16]!;"
        "stp x18,x30,[sp,#-16]!;"
        ""
		"mov x0, sp;"
		"str x0, [%2];"
		"mov sp, %0;"
		"blr %1;"
		""
        "ldr x0, [%2];"
        "mov sp, x0;"
        ""
        "ldp x18,x30,[sp],#16;"
        "ldp x16,x17,[sp],#16;"
        "ldp x14,x15,[sp],#16;"
        "ldp x12,x13,[sp],#16;"
        "ldp x10,x11,[sp],#16;"
        "ldp x8,x9,[sp],#16;"
        "ldp x6,x7,[sp],#16;"
        "ldp x4,x5,[sp],#16;"
        "ldp x2,x3,[sp],#16;"
        "ldp x0,x1,[sp],#16;" :: "r"(correctedAppStackEnd), "r"(mainApp), "r"(&osSP) : "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x30"
	);
}

int mainApp(int argc, char *argv[])
{
#if CONFIG_APPHELLOWORLD_PRINTARGS || CONFIG_APPHELLOWORLD_SPINNER
	int i;
#endif

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
	printf("Hello world!\n");
#if CONFIG_APPHELLOWORLD_PRINTARGS
	printf("Arguments: ");
	for (i=0; i<argc; ++i)
		printf(" \"%s\"", argv[i]);
	printf("\n");
#endif /* CONFIG_APPHELLOWORLD_PRINTARGS */

#if CONFIG_APPHELLOWORLD_SPINNER
	i = 0;
	printf("\n\n\n");
	for (;;) {
		i %= (monkey3_frame_count * 3);
		printf("\r\033[2A %s \n", monkey3[i++]);
		printf(" %s \n",          monkey3[i++]);
		printf(" %s ",            monkey3[i++]);
		fflush(stdout);
		millisleep(250);
	}
#endif /* CONFIG_APPHELLOWORLD_SPINNER */
}
