#include <stdio.h>

int main()
{
    int arr[] = {7, 2, 1, 5, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    int min = arr[0], max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Min: %d, Max: %d", min, max);
}