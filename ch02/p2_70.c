#include <stdio.h>
#include <stdint.h>

unsigned fits_bits(unsigned x, int n)
{
    int w = sizeof(int) >> 3;
    return x == x << (w - n) >> (w - n);
}

int main()
{
    int n;
    unsigned x = 0x12345678;
    n = 0;
    printf("%d, %x\n", n, fits_bits(x, n));
    n = 1;
    printf("%d, %x\n", n, fits_bits(x, n));
    n = 4;
    printf("%d, %x\n", n, fits_bits(x, n));
    n = 20;
    printf("%d, %x\n", n, fits_bits(x, n));
    n = 31;
    printf("%d, %x\n", n, fits_bits(x, n));
    n = 32;
    printf("%d, %x\n", n, fits_bits(x, n));

    return 1;
}