#include <stdio.h>
#include <stdlib.h>
#include "array_functions.h"

int **createTranspose(int **matrix, int rows, int cols) {
    int **transpose = create2dMatrix(cols, rows);
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    return transpose;
}

int **multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int cols2) {
    int **result = create2dMatrix(rows1, cols2);
    
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    return result;
}

int main() {
    int rows, cols;
    
    printf("Enter dimensions of the matrix (rows cols): ");
    scanf("%d %d", &rows, &cols);
    
    printf("\nEnter elements of the matrix:\n");
    int **matrix = create2dMatrix(rows, cols);
    take2darrayInput(matrix, rows, cols);
    
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, rows, cols);
    
    int **transpose = createTranspose(matrix, rows, cols);
    printf("\nTranspose Matrix:\n");
    printMatrix(transpose, cols, rows);
    
    int **result = multiplyMatrices(matrix, transpose, rows, cols, rows);
    
    printf("\nMatrix multiplied with its transpose:\n");
    printMatrix(result, rows, rows);
    
    freeMatrix(matrix, rows);
    freeMatrix(transpose, cols);
    freeMatrix(result, rows);
    
    return 0;
}