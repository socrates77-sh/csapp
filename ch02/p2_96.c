#include <stdio.h>
typedef unsigned float_bits;

int float_f2i(float_bits f)
{
    unsigned sig = f >> 31;
    unsigned e = (f >> 23) & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned bias = 0x7f;
    int val; //num
    unsigned E;
    unsigned M;
    if (e >= 0 && e < bias + 0)
        val = 0;
    else if (e >= 31 + bias)
        val = 0x80000000;
    else
    {
        E = e - bias;
        M = frac | 0x800000;
        if (E > 23)
        {
            val = M << (E - 23);
        }
        else
        {
            val = M >> (23 - E);
        }
    }
    if (sig)
        return -val;
    else
        return val;
}

int main()
{
    float_bits x;
    x = 0x103f2;
    printf("%x %x\n", x, float_f2i(x));

    x = 0xf001f3f2;
    printf("%x %x\n", x, float_f2i(x));

    x = 0x7ff00000;
    printf("%x %x\n", x, float_f2i(x));

    x = 0xfff00000;
    printf("%x %x\n", x, float_f2i(x));

    return 1;
}