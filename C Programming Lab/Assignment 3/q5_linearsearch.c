#include <stdio.h>
#include <stdlib.h>

void searchItemInArray(int *arr, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("Element is present at index: %d\n",i);
            return;
        }
    }

    printf("Number is not found\n");
}

int main()
{

    printf("Enter Length of the array: \n");
    int size;
    scanf("%d", &size);
    int *arr = malloc(size * sizeof(int));

    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    int element;
    scanf("%d", &element);
    searchItemInArray(arr, size, element);
    free(arr);
}