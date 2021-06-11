#include <stdio.h>
#include <stdint.h>

int odd_ones(unsigned x)
{
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 0x1;
}

int main()
{
    unsigned x;
    x = 0x55555555;
    printf("%x, %d\n", x, odd_ones(x));
    x = 0;
    printf("%x, %d\n", x, odd_ones(x));
    x = 0xffffffff;
    printf("%x, %d\n", x, odd_ones(x));
    x = 0x2;
    printf("%x, %d\n", x, odd_ones(x));
    x = 0xa;
    printf("%x, %d\n", x, odd_ones(x));
    x = 0xb00;
    printf("%x, %d\n", x, odd_ones(x));

    return 1;
}