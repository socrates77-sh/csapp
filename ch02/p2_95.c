#include <stdio.h>
typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
    unsigned sig = f >> 31;
    unsigned e = (f >> 23) & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned tail = f & 0x7ffffffff;
    if (e == 0xff)
        return f;
    int ass = (frac & 0x3) == 0x3;
    if (e == 0)
    {
        frac = frac >> 1;
        frac = frac + ass;
    }
    else if (e == 1)
    {
        tail = tail >> 1;
        tail = tail + ass;
        e = (tail >> 23) & 0xff;
        frac = tail & 0x7fffff;
    }
    else
    {
        e = e - 1;
    }
    return sig << 31 | e << 23 | frac;
}

int main()
{
    float_bits x;
    x = 0x1f3f2;
    printf("%x %x\n", x, float_half(x));

    x = 0xf001f3f2;
    printf("%x %x\n", x, float_half(x));

    x = 0x7ff00000;
    printf("%x %x\n", x, float_half(x));

    x = 0xfff00000;
    printf("%x %x\n", x, float_half(x));

    return 1;
}