#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "array_functions.h"
#define ROW 2
#define COL 2

int normofMatrix(int matrix[ROW][COL])
{
    int i, j, sum = 0, norm = INT_MIN;
    for (j = 0; j < COL; j++)
    {
        for (i = 0; i < ROW; i++)
        {
            sum += abs(matrix[i][j]);
        }
        if (norm < sum)
            norm = sum;
    }

    return norm;
}
int main()
{
    int row, col;
    // printf("Enter Row Size: ");
    // scanf("%d", &row);
    // printf("Enter Col Size: ");
    // scanf("%d", &col);

    // int **matrix, i, j;
    // matrix = (int **)malloc(sizeof(int *) * row);

    // for (i = 0; i < row; i++)
    // {
    //     matrix[i] = malloc(sizeof(int) * col);
    // }

    row = 2, col = 2;
    int matrix[ROW][COL];
    // takeInputIn2dIntArray(matrix, row, col);
    int i, j, sum = 0, norm = INT_MIN;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("Enter element [%d][%d]", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (j = 0; j < COL; j++)
    {
        sum = 0;
        for (i = 0; i < ROW; i++)
        {
            sum += abs(matrix[i][j]);
        }
        printf("Sum Col%d\n", i);
        if (norm < sum)
            norm = sum;
    }
    // printf("\nNorm is %d\n", normofMatrix(matrix[ROW][COL]));
    printf("\nNorm is %d\n", norm);

    // free(matrix);
    return 0;
}