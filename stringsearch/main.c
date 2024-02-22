#include <stdio.h>
#include <stdint.h>
/* Import user configuration: */
#ifdef __Unikraft__
#include <uk/config.h>
#endif /* __Unikraft__ */


/* +++Date last modified: 05-Jul-1997 */

/*
**        A Pratt-Boyer-Moore string search, written by Jerry Coffin
**  sometime or other in 1991.  Removed from original program, and
**  (incorrectly) rewritten for separate, generic use in early 1992.
**  Corrected with help from Thad Smith, late March and early
**  April 1992...hopefully it's correct this time. Revised by Bob Stout.
**
**  This is hereby placed in the Public Domain by its author.
**
**  10/21/93 rdg  Fixed bug found by Jeff Dunlop
*/

#include <stddef.h>
#include <string.h>
#include <limits.h>
/*Rename "init" and "strsearch" in the main function with corresponding Algorithm
e.g bmhi_init" and  "bmhi_search" instead*/
#include "bmhasrch.h"
//#include "bmhisrch.h"
#include "bmhsrch.h"
//#include "input_small.h"
#include "input_large.h"
#include "../mem_regions.h"
#include "../work_around.h"
#define DATA 0
#define BSS 0
#define HEAP 0
#define STACK 0


static size_t table[UCHAR_MAX + 1];
static size_t len;
static char *findme;

/*
**  Call this with the string to locate to initialize the table
*/

void init_search(const char *string)
{
      size_t i;

      len = strlen(string);
      for (i = 0; i <= UCHAR_MAX; i++)                      /* rdg 10/93 */
            table[i] = len;
      for (i = 0; i < len; i++)
            table[(unsigned char)string[i]] = len - i - 1;
      findme = (char *)string;
}

/*
**  Call this with a buffer to search
*/

char *strsearch(const char *string)
{
      register size_t shift;
      register size_t pos = len - 1;
      char *here;
      size_t limit=strlen(string);

      while (pos < limit)
      {
            while( pos < limit &&
                  (shift = table[(unsigned char)string[pos]]) > 0)
            {
                  pos += shift;
            }
            if (0 == shift)
            {
                  if (0 == strncmp(findme,
                        here = (char *)&string[pos-len+1], len))
                  {
                        return(here);
                  }
                  else  pos++;
            }
      }
      return NULL;
}


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

// Not possible to build into unikraft-rollback version due unknown required configuration.
int mainApp(int argc, char *argv[])
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
      printf("Hello stringsearch!\n");

      char *here;
      int i;

      for (i = 0; find_strings[i]; i++)
      {

            int len = strlen(search_strings[i]);
            bmh_init(find_strings[i]);
            here = bmh_search(search_strings[i],len);
            printf("\"%s\" is%s in \"%s\"", find_strings[i],
                  here ? "" : " not", search_strings[i]);
            if (here)
                  printf(" [\"%s\"]", here);
            putchar('\n');
      }
      printf("Goodbye stringsearch!\n");
      return 0;
      #endif

}
