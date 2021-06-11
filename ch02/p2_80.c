#include <stdio.h>
#include <stdint.h>

int threeforths(int x)
{
    int sig = x & INT32_MIN;
    int head = x & ~0x3;
    int tail = x & 0x3;
    int head_d4 = head >> 2;
    int head_3md4 = (head_d4 << 1) + head_d4;
    int tail_3m = (tail << 1) + tail;
    int bias = (1 << 2) - 1;
    (sig && (tail_3m += bias));
    int tail_3md4 = tail_3m >> 2;
    return head_3md4 + tail_3md4;
}

int main()
{
    int x;
    x = 3;
    printf("%d, %d\n", x, threeforths(x));
    x = 4;
    printf("%d, %d\n", x, threeforths(x));
    x = -3;
    printf("%d, %d\n", x, threeforths(x));
    x = -4;
    printf("%d, %d\n", x, threeforths(x));

    return 1;
}