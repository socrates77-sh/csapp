#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask;
    mask = 0xff << 8 * i;
    return (x & ~mask) | (b << 8 * i);
}

void main()
{
    unsigned a;
    a = replace_byte(0x12345678, 2, 0xab);
    printf("%x\n", a);
    a = replace_byte(0x12345678, 0, 0xab);
    printf("%x\n", a);
}