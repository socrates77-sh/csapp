#include <stdio.h>
#include <stdint.h>

int lower_one_mask(int n)
{
    int w = sizeof(int) >> 3;
    return (unsigned)-1 >> (w - n);
}

int main()
{
    int n;
    n = 0;
    printf("%d, %x\n", n, lower_one_mask(n));
    n = 1;
    printf("%d, %x\n", n, lower_one_mask(n));
    n = 6;
    printf("%d, %x\n", n, lower_one_mask(n));
    n = 17;
    printf("%d, %x\n", n, lower_one_mask(n));
    n = 31;
    printf("%d, %x\n", n, lower_one_mask(n));
    n = 32;
    printf("%d, %x\n", n, lower_one_mask(n));

    return 1;
}