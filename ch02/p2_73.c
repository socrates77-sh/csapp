#include <stdio.h>
#include <stdint.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    int mask = INT32_MIN;
    int pos_over = !(x & mask) && !(y & mask) && (sum & mask);
    int neg_over = (x & mask) && (y & mask) && !(sum & mask);
    (pos_over && (sum = INT32_MAX)) || (neg_over && (sum = INT32_MIN));
    return sum;
}

int main()
{
    int x, y;
    x = 123456;
    y = 565210;
    printf("%d + %d, %x %x\n", x, y, x + y, saturating_add(x, y));
    x = -123456;
    y = 565210;
    printf("%d + %d, %x %x\n", x, y, x + y, saturating_add(x, y));
    x = 2047483647;
    y = -2000000000;
    printf("%d + %d, %x %x\n", x, y, x + y, saturating_add(x, y));
    x = 2047483647;
    y = 2000000000;
    printf("%d + %d, %x %x\n", x, y, x + y, saturating_add(x, y));
    x = -2047483647;
    y = -2000000000;
    printf("%d + %d, %x %x\n", x, y, x + y, saturating_add(x, y));
    

    return 1;
}