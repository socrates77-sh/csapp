#include <stdio.h>
#include <stdint.h>

int divide_power2(int x, int k)
{
    // int w = sizeof(int) << 3;
    int sig = x & INT32_MIN;
    (sig && (x = x + (1 << k) - 1));
    return x >> k;
}

int mul3div4(int x)
{
    x = (x << 1) + x;
    return divide_power2(x, 2);
}

int main()
{
    int x = INT32_MIN;
    printf("%d, %d\n", x, mul3div4(x));

    x = INT32_MIN + 1;
    printf("%d, %d\n", x, mul3div4(x));

    x = INT32_MAX;
    printf("%d, %d\n", x, mul3div4(x));

    x = INT32_MAX - 1;
    printf("%d, %d\n", x, mul3div4(x));

    return 1;
}