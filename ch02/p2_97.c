#include <stdio.h>
#include <stdint.h>
typedef unsigned float_bits;

int bits_length(int i)
{
    if ((i & INT32_MIN) != 0)
        return 32;
    unsigned u = (unsigned)i;
    int length = 0;
    while (u >= (1 << length))
        length++;
    return length;
}
unsigned bits_mask(int l)
{
    return (unsigned)-1 >> (32 - 1);
}
float_bits float_i2f(int i)
{
    unsigned sig, exp, rest, frac, exp_sig, round_part;
    unsigned bits, fbits;
    unsigned bias = 0x7f;
    if (i == 0)
    {
        sig = 0;
        exp = 0;
        frac = 0;
        return sig << 31 | exp << 23 | frac;
    }
    if (i == INT32_MIN)
    {
        sig = 1;
        exp = bias + 31;
        frac = 0;
        return sig << 31 | exp << 23 | frac;
    }
    sig = 0;
    if (i < 0)
    {
        sig = 1;
        i = -i;
    }
    bits = bits_length(i);
    fbits = bits - 1;
    exp = bias + fbits;
    rest = i & bits_mask(fbits);
    if (fbits <= 23)
    {
        frac = rest << (23 - fbits);
        exp_sig = exp << 23 | frac;
    }
    else
    {
        int offset = fbits - 23;
        int round_mid = 1 << (offset - 1);
        round_part = rest & bits_mask(offset);
        frac = rest >> offset;
        exp_sig = exp << 23 | frac;
        if (round_part < round_mid)
        {
            //lalala
        }
        else if (round_part > round_mid)
        {
            exp_sig = exp_sig + 1;
        }
        else
        {
            if ((frac & 0x1) == 1)
            {
                exp_sig = exp_sig + 1;
            }
        }
    }
    return sig << 31 | exp_sig;
}

int main()
{
    float_bits x;
    x = 0x103f2;
    printf("%x %f\n", x, float_i2f(x));

    x = 0xf001f3f2;
    printf("%x %f\n", x, float_i2f(x));

    x = 0x7ff00000;
    printf("%x %f\n", x, float_i2f(x));

    x = 0xfff00000;
    printf("%x %f\n", x, float_i2f(x));

    return 1;
}