#include <stdio.h>

unsigned f2u(float x)
{
    return *(unsigned *)&x;
}

int float_le(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;
    return (ux << 1 == 0 && uy << 1 == 0) ||
           (sx && !sy) ||
           (!sx && !sy && ux <= uy) ||
           (sx && sy && ux >= uy);
}

int main()
{
    float x, y;
    x=-0;
    y=+0;
    printf("%x %x %d\n", f2u(x), f2u(y), float_le(x, y));
    x=+0;
    y=-0;
    printf("%x %x %d\n", f2u(x), f2u(y), float_le(x, y));

    x=1.1;
    y=-1.2;
    printf("%x %x %d\n", f2u(x), f2u(y), float_le(x, y));

    x=1.1;
    y=1.2;
    printf("%x %x %d\n", f2u(x), f2u(y), float_le(x, y));

    return 1;
}
