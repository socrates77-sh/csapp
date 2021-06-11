#include <stdio.h>
#include <stdint.h>

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    int w = sizeof(int) * 8;
    uint64_t mask = ((uint64_t)1 << (w - k)) - 1;
    return xsra & mask;
}

int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    int w = sizeof(int) * 8;
    unsigned sign = ((unsigned)x & 1 << (w - 1)) != 0;
    uint64_t mask = ~(((uint64_t)sign << (w - k)) - 1);
    return xsrl | mask;
}

int main()
{
    unsigned ux;
    ux = 0xf1236789;
    printf("%x : %x\n", ux, srl(ux, 4));
    printf("%x : %x\n", ux, srl(ux, 24));
    printf("%x : %x\n", ux, srl(ux, 0));
    printf("%x : %x\n", ux, srl(ux, 31));
    ux = 0x71236789;
    printf("%x : %x\n", ux, srl(ux, 4));
    printf("%x : %x\n", ux, srl(ux, 24));
    printf("%x : %x\n", ux, srl(ux, 0));
    printf("%x : %x\n", ux, srl(ux, 31));

    int x;
    x = 0xf1236789;
    printf("%x (%d): %x\n", x, x, sra(x, 4));
    printf("%x (%d): %x\n", x, x, sra(x, 24));
    printf("%x (%d): %x\n", x, x, sra(x, 0));
    printf("%x (%d): %x\n", x, x, sra(x, 31));
    x = 0x71236789;
    printf("%x (%d): %x\n", x, x, sra(x, 4));
    printf("%x (%d): %x\n", x, x, sra(x, 24));
    printf("%x (%d): %x\n", x, x, sra(x, 0));
    printf("%x (%d): %x\n", x, x, sra(x, 31));

    return 1;
}