void quick_sort_f(unsigned long *begin, unsigned long *end);
void quick_sort_b(unsigned long *begin, unsigned long *end);

unsigned long sort_buffer[8000];
unsigned int number;

void quick_sort_f(unsigned long *begin, unsigned long *end) {
    if (begin + 2 >= end) {
        printf("Reached end of recursion: %d\n",number++);
        return;
    }
    // log_info("Sorting");
    unsigned long *pivot_element = end - 1;

    unsigned long *li = begin;
    unsigned long *ri = end - 1;

    while (li < ri) {
        while (li < end - 2 && *li < *pivot_element) li++;
        while (ri > begin && *ri >= *pivot_element) ri--;

        if (li < ri) {
            unsigned long buffer = *li;
            *li = *ri;
            *ri = buffer;
        }
    }
    // log_info("Done swapping");

    if (*li > *pivot_element) {
        unsigned long buffer = *li;
        *li = *pivot_element;
        *pivot_element = buffer;
    }

    // log_info("Recursive call");
    quick_sort_f(begin, li);
    quick_sort_f(li + 1, end);
}

void quick_sort_b(unsigned long *begin, unsigned long *end) {
    if (begin + 2 >= end) {
        return;
    }
    // log_info("Sorting");
    unsigned long *pivot_element = end - 1;

    unsigned long *li = begin;
    unsigned long *ri = end - 1;

    while (li < ri) {
        while (li < end - 2 && *li > *pivot_element) li++;
        while (ri > begin && *ri <= *pivot_element) ri--;

        if (li < ri) {
            unsigned long buffer = *li;
            *li = *ri;
            *ri = buffer;
        }
    }
    // log_info("Done swapping");

    if (*li < *pivot_element) {
        unsigned long buffer = *li;
        *li = *pivot_element;
        *pivot_element = buffer;
    }

    // log_info("Recursive call");
    quick_sort_b(begin, li);
    quick_sort_b(li + 1, end);
}