#include <stdio.h>
#include <stdlib.h>
#include "print_array.h"

enum SortType
{
    asc,
    desc
};

void merge(int *arr, int low, int mid, int high, enum SortType s)
{
    int size = high - low + 1;
    int *arr2 = malloc(size * sizeof(int));
    int left = low, i = 0;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if ((s == asc && arr[left] <= arr[right]) || (s == desc && arr[left] >= arr[right]))
        {
            arr2[i++] = arr[left++];
        }
        else
        {
            arr2[i++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        arr2[i++] = arr[left++];
    }

    while (right <= high)
    {
        arr2[i++] = arr[right++];
    }

    for (int j = low; j <= high; j++)
    {
        arr[j] = arr2[j - low];
    }
    free(arr2);
}

void MergeSort(int *arr, int low, int high, enum SortType s)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid, s);
    MergeSort(arr, mid + 1, high, s);
    merge(arr, low, mid, high, s);
}

int main()
{
    int arr[] = {2, 4, 9, 8, 1, 13, 5, 10, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int mid = size / 2;
    MergeSort(arr, 0, mid, desc);
    MergeSort(arr, mid + 1, size - 1, asc);
    printIntArray(arr, size);
}
