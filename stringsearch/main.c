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


int main(int argc, char *argv[])
{


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
}