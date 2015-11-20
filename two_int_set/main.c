#include "stdlib.h"
#include "string.h"


/*
 * Make sure set_inter has enough space
 */
void get_inter_int(int *set_a, int len_a,
                   int *set_b, int len_b,
                   int *set_inter)
{
    int min_value, max_value, alloc_len;
    int *shorter, shorter_len, *longer, longer_len;
    int i, j = 0, temp;
    unsigned char *buf;

    /* Get the shorter set */
    if (len_a < len_b) {
        shorter = set_a;
        shorter_len = len_a;
        longer = set_b;
        longer_len = len_b;
    } else {
        shorter = set_b;
        shorter_len = len_b;
        longer = set_a;
        longer_len = len_a;
    }

    /* Get the min/max value in the shorter set */
    min_value = max_value = shorter[0];
    for (i = 0; i < shorter_len; i++) {
        if (shorter[i] < min_value)
            min_value = shorter[i];
        else if (shorter[i] > max_value)
            max_value = shorter[i];
    }

    /* Alloc bit map, and set bit */
    alloc_len = (max_value - min_value + 1 + 7) / 8;
    buf = (unsigned char *)malloc(alloc_len);
    memset(buf, 0, alloc_len);
    for (i = 0; i < shorter_len; i++) {
        temp = shorter[i] - min_value;
        buf[temp / 8] |= 1 << (temp % 8);
    }

    /* Judge the longer */
    for (i = 0; i < longer_len; i++) {
        temp = longer[i] - min_value;
        if (temp >=0 && temp <= max_value - min_value) {
            if (buf[temp / 8] & (1 << (temp % 8)))
                set_inter[j++] = longer[i];
        }
    }
}


int main(void)
{
    int a[4] = {1, 2, 3, 4};
    int b[4] = {3, 4};
    int inter[4] = {0};

    get_inter_int(a, 4, b, 2, inter);

    return 0;
}
