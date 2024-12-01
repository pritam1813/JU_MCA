#include <stdio.h>

int main()
{
    printf("Size of Integer: %lu Bytes\n", sizeof(int));
    printf("Size of Character: %lu Bytes\n", sizeof(char));
    printf("Size of Float: %lu Bytes\n", sizeof(float));
    printf("Size of Double: %lu Bytes\n", sizeof(double));

    printf("Size of Long Double: %lu Bytes\n", sizeof(long double));
    printf("Size of Pointer: %lu Bytes\n", sizeof(void *));

    return 0;
}