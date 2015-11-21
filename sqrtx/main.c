#include "stdio.h"


static float precision = 0.000001;

/*
 * Pass point (a, b) tangent equation is y = k(x - a) + b,
 * so when y = 0, x = a - b / k, with y = x ^ 2 - m,
 * b = a ^ 2 - m, k = 2a, so x = a / 2 + m / 2 / a,
 * or x(cur) = x(pre) / 2 + m / 2 / x(pre)
 */
float sqrtx(float x)
{
    float cur, pre;

    cur = x;

    do {
        pre = cur;
        cur = pre / 2 + x / 2 / pre;
    } while (pre - cur > precision);

    return cur;
}

int main(void)
{
    int x;

    printf("Input a value to sqrtx:\n");
    scanf("%d", &x);

    printf("The sqrtx of %d is %f", x, sqrtx(x));

    return 0;
}
