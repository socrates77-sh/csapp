#include <stdio.h>
#include <stdint.h>

int divide_power2(int x, int k)
{
    // int w = sizeof(int) << 3;
    int sig = x & INT32_MIN;
    (sig && (x = x + (1 << k) - 1));
    return x >> k;
}

int main()
{
    int x = INT32_MIN;
    int k = 0;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 3;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 31;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 32;
    printf("%d, %d\n", x, divide_power2(x, k));

    x = INT32_MIN + 1;
    k = 0;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 3;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 31;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 32;
    printf("%d, %d\n", x, divide_power2(x, k));

    x = INT32_MAX;
    k = 0;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 3;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 31;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 32;
    printf("%d, %d\n", x, divide_power2(x, k));

    x = INT32_MAX - 1;
    k = 0;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 3;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 31;
    printf("%d, %d\n", x, divide_power2(x, k));
    k = 32;
    printf("%d, %d\n", x, divide_power2(x, k));

    return 1;
}