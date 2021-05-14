#include <stdio.h>

int int_shifts_are_arithmetic()
{
    return -1>>1 == -1;
}

void main()
{
    printf("int_shifts_are_arithmetic: %d\n", int_shifts_are_arithmetic());
}