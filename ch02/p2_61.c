#include <stdio.h>

int is_all_one(int x)
{
    int mask = -1;
    return !(x ^ mask);
}

int is_all_zero(int x)
{
    int mask = 0;
    return !(x ^ mask);
}

int is_lbyte_ff(int x)
{
    int mask = 0xff;
    return !((x & mask) ^ mask);
}

int is_mbyte_00(int x)
{
    int mask = 0xff << ((sizeof(int)-1)<<3);
    return !((x & mask) ^ 0);
}

void main()
{
    int x;
    x = 0;
    printf("%d is_all_one: %d\n", x, is_all_one(x));
    x = 1;
    printf("%d is_all_one: %d\n", x, is_all_one(x));
    x = 100;
    printf("%d is_all_one: %d\n", x, is_all_one(x));
    x = 1000;
    printf("%d is_all_one: %d\n", x, is_all_one(x));
    x = -1;
    printf("%d is_all_one: %d\n", x, is_all_one(x));

    x = 0;
    printf("%d is_all_zero: %d\n", x, is_all_zero(x));
    x = 1;
    printf("%d is_all_zero: %d\n", x, is_all_zero(x));
    x = 100;
    printf("%d is_all_zero: %d\n", x, is_all_zero(x));
    x = -1;
    printf("%d is_all_zero: %d\n", x, is_all_zero(x));

    x = 0;
    printf("%d is_lbyte_ff: %d\n", x, is_lbyte_ff(x));
    x = 1;
    printf("%d is_lbyte_ff: %d\n", x, is_lbyte_ff(x));
    x = 4095;
    printf("%d is_lbyte_ff: %d\n", x, is_lbyte_ff(x));
    x = -1;
    printf("%d is_lbyte_ff: %d\n", x, is_lbyte_ff(x));
    x = 255;
    printf("%d is_lbyte_ff: %d\n", x, is_lbyte_ff(x));

    x = 0;
    printf("%d is_mbyte_00: %d\n", x, is_mbyte_00(x));
    x = 1;
    printf("%d is_mbyte_00: %d\n", x, is_mbyte_00(x));
    x = 1<<25;
    printf("%d is_mbyte_00: %d\n", x, is_mbyte_00(x));
    x = -1;
    printf("%d is_mbyte_00: %d\n", x, is_mbyte_00(x));
    x = 255;
    printf("%x is_mbyte_00: %d\n", x, is_mbyte_00(x));
}