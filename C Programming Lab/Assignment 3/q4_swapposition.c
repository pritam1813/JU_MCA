#include <stdio.h>
#include "swap.h"
#include "print_array.h"

int main()
{
    int arr[] = {5, 1, 2, 7, 9, 8};
    int len = 6;

    if (len % 2 != 0)
    {
        len--;
    }
    for (int i = 0; i < len; i += 2)
    {
        swap(&arr[i], &arr[i + 1]);
    }

    printarray(arr, 6);
}