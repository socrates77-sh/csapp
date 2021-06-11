#include <stdio.h>
#include <stdint.h>

unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) >> 3;
    return x << n | x >> (w - n);
}

int main()
{
    int n;
    unsigned x = 0x12345678;
    n = 0;
    printf("%d, %x\n", n, rotate_left(x, n));
    n = 1;
    printf("%d, %x\n", n, rotate_left(x, n));
    n = 4;
    printf("%d, %x\n", n, rotate_left(x, n));
    n = 20;
    printf("%d, %x\n", n, rotate_left(x, n));
    n = 31;
    printf("%d, %x\n", n, rotate_left(x, n));
    n = 32;
    printf("%d, %x\n", n, rotate_left(x, n));

    return 1;
}