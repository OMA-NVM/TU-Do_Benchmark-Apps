typedef unsigned char uint8_t;
unsigned int number;
unsigned int sort[];

void app_init() {
    unsigned int sort_size = 8000;
    printf("Starting to sort %d numbers\n", sort_size);
    quick_sort(random_number, random_number + sort_size);

    unsigned char before = 0;
    unsigned char sane = 1;
    for (unsigned long i = 0; i < sort_size; i++) {
      printf("Array[%d] = %d\n", i, random_number[i]);
      if (before > random_number[i] ) {
        sane = 0;
      }
    }
    if (sane == 0)
      printf("Program is no longer syntactical correct!\n");
}

//          QUICKSORT START

void quick_sort(unsigned char *begin, unsigned char *end) {
    //printf("Begin: %d, End; %d\n", *begin,  *end);
    //void *sp;
    //__asm__ __volatile__ ("mov %0, sp" : "=r"(sp));
    if (begin + 2 >= end) {
        
        //register void *sp asm ("sp");
        //printf("%p", sp);
        printf("Reached end of recursion: %d\n",number++);
        return;
    }
    unsigned char *pivot_element = end - 1;

    unsigned char *li = begin;
    unsigned char *ri = end - 1;

    // printf("Resorting loop\n");
    while (li < ri) {
        while (li < end - 2 && *li < *pivot_element) li++;
        while (ri > begin && *ri >= *pivot_element) ri--;

        if (li < ri) {
            unsigned char buffer = *li;
            *li = *ri;
            *ri = buffer;
        }
    }

    // printf("Resorting loop end\n");

    if (*li > *pivot_element) {
        unsigned char buffer = *li;
        *li = *pivot_element;
        *pivot_element = buffer;
    }

    // printf("LCalling qsort at 0x%lx\n", quick_sort);
    quick_sort(begin, li);
    // printf("RCalling qsort at 0x%lx\n", quick_sort);
    quick_sort(li + 1, end);
}

//			QUICKSORT END 



void app_init_bss(){
    unsigned int sort_size = 8000;
    for (int i = 0; i < sort_size; i++)
    {
        sort[i] = random_number[i];
    }
    
    printf("Starting to sort %d numbers\n", sort_size);
    quick_sort(sort, sort + sort_size);

    unsigned char before = 0;
    unsigned char sane = 1;
    for (unsigned long i = 0; i < sort_size; i++) {
      printf("Array[%d] = %d\n", i, sort[i]);
      if (before > sort[i] ) {
        sane = 0;
      }
    }
    if (sane == 0)
      printf("Program is no longer syntactical correct!\n");
}