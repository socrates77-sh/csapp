#include <stdio.h>
#include <stdint.h>

int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t)x * (int64_t)y;
    int w = sizeof(int) << 3;
    return mul >> w;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int sig_x = x >> 31;
    int sig_y = y >> 31;
    int signed_prod = signed_high_prod(x, y);
    return signed_prod + x * sig_y + y * sig_x;
}

int main()
{
    unsigned x, y;
    x = 123456;
    y = 565210;
    printf("%x * %x, %x %x\n", x, y, x * y, unsigned_high_prod(x, y));
    x = -2047483647;
    y = 111565210;
    printf("%x * %x, %x %x\n", x, y, x * y, unsigned_high_prod(x, y));
    x = 2047483647;
    y = -2000000000;
    printf("%x * %x, %x %x\n", x, y, x * y, unsigned_high_prod(x, y));
    x = 2047483647;
    y = 2000000000;
    printf("%x * %x, %x %x\n", x, y, x * y, unsigned_high_prod(x, y));
    x = -2047483647;
    y = -2000000000;
    printf("%x * %x, %x %x\n", x, y, x * y, unsigned_high_prod(x, y));

    return 1;
}