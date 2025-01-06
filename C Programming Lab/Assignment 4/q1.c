#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right, int order)
{
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if ((order == 1 && arr[j] <= pivot) || (order == -1 && arr[j] >= pivot))
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[right]);

    return i;
}

void quickSelect(int *arr, int left, int right, int k, int order)
{
    if (left <= right)
    {
        int pivotIdx = partition(arr, left, right, order);

        int leftCnt = pivotIdx - left + 1;

        if (leftCnt == k)
            return;

        if (leftCnt > k)
        {
            quickSelect(arr, left, pivotIdx - 1, k, order);
        }
        else
        {
            quickSelect(arr, pivotIdx + 1, right, k - leftCnt, order);
        }
    }
}

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 5;
    quickSelect(arr, 0, n - 1, k, 1);
    printf("The %d-th smallest element is: %d\n", k, arr[k - 1]);

    int arr2[] = {1, 23, 12, 9, 30, 2, 50, 28};

    k = 3;
    quickSelect(arr2, 0, n - 1, k, -1);
    printf("The %d-th largest element is: %d\n", k, arr2[k - 1]);

    return 0;
}
