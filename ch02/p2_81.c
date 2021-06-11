#include <stdio.h>
#include <stdint.h>

int patternGenerator1(int k)
{
    return -1 << k;
}

int patternGenerator2(int k, int j)
{
    return (~(-1 << k)) << j;
}

int main()
{
    int k, j;
    k = 5;
    printf("%x, k=%d\n", patternGenerator1(k), k);
    k = 5;
    j = 3;
    printf("%x, k=%d, j=%d\n", patternGenerator2(k, j), k, j);

    return 1;
}