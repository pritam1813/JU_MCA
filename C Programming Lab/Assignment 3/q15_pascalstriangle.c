#include <stdio.h>
#include <stdlib.h>
#include "print_array.h"
#define pascalupto 9

int main()
{

    int **arr = (int **)malloc(pascalupto * sizeof(int *));

    for (int i = 0; i < pascalupto; i++)
    {
        arr[i] = malloc((i + 1) * sizeof(int));
    }

    for (int i = 0; i < pascalupto; i++)
    {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (int i = 0; i < pascalupto; i++)
    {
        for (int j = 0; j <= i; j++)
        {

            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    freeMatrix(arr, pascalupto);
}