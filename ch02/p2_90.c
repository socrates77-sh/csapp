#include <stdio.h>
#include <math.h>

float u2f(unsigned x)
{
    return *(float *)&x;
}

float fpwr2(int x)
{
    unsigned exp, frac;
    unsigned u;
    if (x < 2 - pow(2, 7) - 23)
    {
        exp = 0;
        frac = 0;
    }
    else if (x < 2 - pow(2, 7))
    {
        exp = 0;
        frac = 1 << (unsigned)(x - (2 - pow(2, 7) - 23));
    }
    else if (x < pow(2, 7) - 1 + 1)
    {
        exp = pow(2, 7) - 1 + x;
        frac = 0;
    }
    else
    {
        exp = 0xFF;
        frac = 0;
    }
    u = exp << 23 | frac;
    return u2f(u);
}

int main()
{
    int x;
    x = -149;
    printf("%d %20.20f\n", x, fpwr2(x));
    x = -150;
    printf("%d %20.20f\n", x, fpwr2(x));
    x = -126;
    printf("%d %20.20f\n", x, fpwr2(x));
    x = -125;
    printf("%d %20.20f\n", x, fpwr2(x));
    x = -50;
    printf("%d %20.20f\n", x, fpwr2(x));

    x = 15;
    printf("%d %20.20f\n", x, fpwr2(x));

    x = 127;
    printf("%d %20.20f\n", x, fpwr2(x));
    x = 128;
    printf("%d %20.20f\n", x, fpwr2(x));

    return 1;
}