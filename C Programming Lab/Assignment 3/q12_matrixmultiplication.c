#include <stdio.h>
#include <stdlib.h>
#include "array_functions.h"


int **multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int cols2) {
    int **result = create2dMatrix(rows1, cols2);
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;
    
    printf("Enter dimensions of first matrix (rows cols): ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter dimensions of second matrix (rows cols): ");
    scanf("%d %d", &rows2, &cols2);
    
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible! Number of columns in first matrix must equal number of rows in second matrix.\n");
        return 1;
    }
    
    printf("\nEnter elements of first matrix:\n");
    int **matrix1 = create2dMatrix(rows1, cols1);
    take2darrayInput(matrix1, rows1, cols1);
    
    printf("\nEnter elements of second matrix:\n");
    int **matrix2 = create2dMatrix(rows2, cols2);
    take2darrayInput(matrix2, rows2, cols2);
    
    printf("\nFirst Matrix:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("\nSecond Matrix:\n");
    printMatrix(matrix2, rows2, cols2);
    
    int **result = multiplyMatrices(matrix1, matrix2, rows1, cols1, cols2);
    
    printf("\nResult Matrix:\n");
    printMatrix(result, rows1, cols2);
    
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(result, rows1);
    
    return 0;
}