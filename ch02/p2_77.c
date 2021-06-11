#include <stdio.h>
#include <stdint.h>

int mul17(int x)
{
    return (x << 4) + x;
}

int mulm7(int x)
{
    return -(x << 3) + x;
}

int mul60(int x)
{
    return (x << 6) - (x<<2);
}

int mulm112(int x)
{
    return -(x << 7) + (x<<4);
}

int main()
{
    int x = 10;
    printf("%d, %d\n", x, mul17(x));
    printf("%d, %d\n", x, mulm7(x));
    printf("%d, %d\n", x, mul60(x));
    printf("%d, %d\n", x, mulm112(x));

    return 1;
}