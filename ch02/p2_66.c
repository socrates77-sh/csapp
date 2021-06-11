#include <stdio.h>
#include <stdint.h>

int leftmost_one(unsigned x)
{
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);

    return (x >> 1) + (x && 1);
}

int main()
{
    unsigned x;
    x = 0xff000000;
    printf("%x, %x\n", x, leftmost_one(x));
    x = 0x00660000;
    printf("%x, %x\n", x, leftmost_one(x));
    x = 0;
    printf("%x, %x\n", x, leftmost_one(x));
    x = 0x00008000;
    printf("%x, %x\n", x, leftmost_one(x));
    x = 1;
    printf("%x, %x\n", x, leftmost_one(x));

    return 1;
}