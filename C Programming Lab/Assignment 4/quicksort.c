#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pritArry(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        while (i <= high - 1 && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= low + 1 && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[low]);
    return j;
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high);
        quicksort(arr, low, part - 1);
        quicksort(arr, part + 1, high);
    }
}

int main()
{
    int arr[] = {10, 8, 6, 9, 12, 18, 2};
    quicksort(arr, 0, 6);
    pritArry(arr, 7);
}