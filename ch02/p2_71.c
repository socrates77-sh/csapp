#include <stdio.h>
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum)
{
    // int w = sizeof(unsigned);
    // int left = (w - bytenum - 1) << 3;
    // int right = (w - 1) << 3;
    // return (int)(word << left >> right);
    return (word >> (bytenum << 3)) & 0xff;
}

int main()
{
    int n;
    unsigned x = 0x12345678;
    n = 0;
    printf("%x, %d, %x\n", x, n, xbyte(x, n));
    x = -114514;
    n = 0;
    printf("%x, %d, %x\n", x, n, xbyte(x, n));
    n = 1;
    printf("%x, %d, %x\n", x, n, xbyte(x, n));
    n = 2;
    printf("%x, %d, %x\n", x, n, xbyte(x, n));
    n = 3;
    printf("%x, %d, %x\n", x, n, xbyte(x, n));
    // printf("%d\n", xbyte(-114514, 0));
    return 1;
}
