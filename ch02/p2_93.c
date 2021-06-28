#include <stdio.h>
typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
    unsigned sig = f >> 31;
    unsigned e = (f >> 23) & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned res = (e << 23) | frac;
    if (e == 0xff && frac)
        res = f;
    return res;
}

int main()
{
    float_bits x;
    x = 0x1f3f2;
    printf("%x %x\n", x, float_absval(x));

    x = 0xf001f3f2;
    printf("%x %x\n", x, float_absval(x));

    x = 0x7ff00000;
    printf("%x %x\n", x, float_absval(x));

    x = 0xfff00000;
    printf("%x %x\n", x, float_absval(x));

    return 1;
}