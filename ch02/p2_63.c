#include <stdio.h>

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    int w = sizeof(int) * 8;
    unsigned mask = (1 << (w - k)) - 1;
    return xsra & mask;
}

void main()
{
    unsigned ux;
    ux = 0xf1236789;
    printf("%x : %x\n", ux, srl(ux, 4));
    printf("%x : %x\n", ux, srl(ux, 24));
    printf("%x : %x\n", ux, srl(ux, 0));
    printf("%x : %x\n", ux, srl(ux, 31));
}