#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian()
{
    int i = 1;
    byte_pointer p_first_byte;
    p_first_byte = (byte_pointer)&i;
    return *p_first_byte == 1;
}

void main()
{
    printf("%d\n", is_little_endian());
}