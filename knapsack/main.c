#include "stdio.h"
#include "stdlib.h"
#include "string.h"


unsigned char *flag;
int length;

void any_sum(int n, int m)
{
    int i;

    if (n == 0 || m == 0)
        return;

    if (m < n)
        n = m;

    if (m == n) {
        flag[n-1] = 1;

        for (i = 0; i < length; i++) {
            if (flag[i])
                printf("%d ", i + 1);
        }
        printf("\n");
    }

    flag[n-1] = 1;              /* Select nth */
    any_sum(n - 1, m - n);
    flag[n-1] = 0;              /* Not select nth */
    any_sum(n - 1, m);
}

int main(void)
{
    int n, m;

    printf("Input n and m:\n");
    scanf("%d%d", &n, &m);

    flag = (unsigned char *)malloc(n);
    memset(flag, 0, n);
    length = n;

    any_sum(n, m);

    return 0;
}
