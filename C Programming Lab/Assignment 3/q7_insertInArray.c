#include <stdio.h>
#include <stdlib.h>
#include "array_functions.h"

int compareFunc(const void *elem1, const void *elem2)
{
    int f = *((int *)elem1);
    int s = *((int *)elem2);
    if (f > s)
        return 1;
    if (f < s)
        return -1;
    return 0;
}

void insertInArray(int *arr, int size, int element)
{
    arr[size - 1] = element;
    qsort(arr, size, sizeof(int), compareFunc);
}

int main()
{
    int size;
    printf("Enter Size of the array: ");
    scanf("%d", &size);

    int *arr = malloc(sizeof(int) * (size));
    printf("Take Elemnts of the Array: ");
    takeInputInIntArray(arr, size);

    int element;
    printf("Enter Element to insert in the Array: ");
    scanf("%d", &element);
    int *new_arr = (int*)realloc(arr, sizeof(int)*(size + 1));
    size++;
    insertInArray(new_arr, size, element);
    printIntArray(new_arr,size);
    free(arr);
    //free(new_arr);
}