#include <stdio.h>

void main()
{
    // unsigned long x, y, z;
    unsigned x, y, z;
    x = 0x89abcdef;
    y = 0x76543210;
    z = (x & 0xff) | (y & ~0xff);

    printf("%0x\n", x);
    printf("%0x\n", y);
    printf("%0x\n", z);
}