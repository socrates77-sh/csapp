#include <stdio.h>
typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
    unsigned sig = f >> 31;
    unsigned e = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (e == 0xFF)
    {
        return f;
    }
    if (e == 0)
    {
        frac <<= 1;
    }
    else
    {
        e += 1;
    }
    return sig << 31 | e << 23 | frac;
}

int main()
{
    float_bits x;
    x = 0x1f3f2;
    printf("%x %x\n", x, float_twice(x));

    x = 0xf001f3f2;
    printf("%x %x\n", x, float_twice(x));

    x = 0x7ff00000;
    printf("%x %x\n", x, float_twice(x));

    x = 0xfff00000;
    printf("%x %x\n", x, float_twice(x));

    return 1;
}