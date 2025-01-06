#include <stdio.h>
#include <stdlib.h>

void printIntArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void takeInputInIntArray(int *arr, int size)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Function to dynamically allocate a 2D matrix
int **create2dMatrix(int rows, int cols)
{
    // Allocate memory for the array of row pointers
    int **matrix = (int **)malloc(rows * sizeof(int *));

    // Check if memory allocation failed
    if (matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); // Exit the program if memory allocation fails
    }

    // Allocate memory for each row
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));

        // Check if memory allocation failed for each row
        if (matrix[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    return matrix;
}

int **take2darrayInput(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("element[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
// Function to free the dynamically allocated 2D matrix
void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]); // Free each row
    }
    free(matrix); // Free the array of row pointers
}

// Function to print the 2D matrix
void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
