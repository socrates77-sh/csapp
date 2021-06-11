#include <stdio.h>
#include <stdint.h>

int any_odd_one(unsigned x)
{
    unsigned mask = 0xaaaaaaaa;
    return !(!(x & mask));
}

int main()
{
    unsigned x;
    x=0x55555555;
    printf("%x, %d\n", x, any_odd_one(x));
    x=0;
    printf("%x, %d\n", x, any_odd_one(x));
    x=0xffffffff;
    printf("%x, %d\n", x, any_odd_one(x));
    x=0x2;
    printf("%x, %d\n", x, any_odd_one(x));
    
    return 1;
}