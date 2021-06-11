#include <stdio.h>
#include <stdint.h>

int tsub_ok(int x, int y)
{
    int sub = x - y;
    return !((x > 0 && y < 0 && sub < 0) || (x < 0 && y > 0 && sub > 0));
}

int main()
{
    int x, y;
    x = 123456;
    y = 565210;
    printf("%d - %d, %d %d\n", x, y, x - y, tsub_ok(x, y));
    x = -2047483647;
    y = 111565210;
    printf("%d - %d, %d %d\n", x, y, x - y, tsub_ok(x, y));
    x = 2047483647;
    y = -2000000000;
    printf("%d - %d, %d %d\n", x, y, x - y, tsub_ok(x, y));
    x = 2047483647;
    y = 2000000000;
    printf("%d - %d, %d %d\n", x, y, x - y, tsub_ok(x, y));
    x = -2047483647;
    y = -2000000000;
    printf("%d - %d, %d %d\n", x, y, x - y, tsub_ok(x, y));

    return 1;
}