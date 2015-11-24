#include "stdio.h"


int to_int(char *s)
{
    int res = 0;
    char *p = s;

    while (*p) {
        res = 10 * res + *p - '0';
        p++;
    }

    return res;
}


int main(void)
{
    char s[64] = {3, 3, 3, 3, 3, 3, 3, 3, 3,};

    printf("Input the str:\n");
    scanf("%s", s);

    printf("The result is %d\n", to_int(s));
}
