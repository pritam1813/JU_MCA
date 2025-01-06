#include <stdio.h>
#include <stdlib.h>
#include "array_functions.h"

int* convertTo1D(int **matrix, int rows, int cols, int *size) {
    *size = rows * cols;
    int *arr = (int*)malloc((*size) * sizeof(int));
    
    int k = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[k++] = matrix[i][j];
        }
    }
    return arr;
}

void convertTo2D(int *arr, int **matrix, int rows, int cols) {
    int k = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = arr[k++];
        }
    }
}

void sortArray(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int* mergeSortedArrays(int *arr1, int size1, int *arr2, int size2, int *mergedSize) {
    *mergedSize = size1 + size2;
    int *merged = (int*)malloc((*mergedSize) * sizeof(int));
    
    int i = 0, j = 0, k = 0;
    
    while(i < size1 && j < size2) {
        if(arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    while(i < size1) {
        merged[k++] = arr1[i++];
    }
    
    while(j < size2) {
        merged[k++] = arr2[j++];
    }
    
    return merged;
}

int main() {
    int rows1, cols1, rows2, cols2;
    
    printf("Enter dimensions of first matrix (rows cols): ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter dimensions of second matrix (rows cols): ");
    scanf("%d %d", &rows2, &cols2);
    
    printf("\nEnter elements of first matrix:\n");
    int **matrix1 = create2dMatrix(rows1, cols1);
    take2darrayInput(matrix1, rows1, cols1);
    
    printf("\nEnter elements of second matrix:\n");
    int **matrix2 = create2dMatrix(rows2, cols2);
    take2darrayInput(matrix2, rows2, cols2);
    
    printf("\nOriginal First Matrix:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("\nOriginal Second Matrix:\n");
    printMatrix(matrix2, rows2, cols2);
    
    int size1, size2;
    int *arr1 = convertTo1D(matrix1, rows1, cols1, &size1);
    int *arr2 = convertTo1D(matrix2, rows2, cols2, &size2);
    
    sortArray(arr1, size1);
    sortArray(arr2, size2);
    
    convertTo2D(arr1, matrix1, rows1, cols1);
    convertTo2D(arr2, matrix2, rows2, cols2);
    
    printf("\nSorted First Matrix:\n");
    printMatrix(matrix1, rows1, cols1);
    printf("\nSorted Second Matrix:\n");
    printMatrix(matrix2, rows2, cols2);
    
    int mergedSize;
    int *mergedArr = mergeSortedArrays(arr1, size1, arr2, size2, &mergedSize);
    
    int mergedRows = (mergedSize + cols1 - 1) / cols1; 
    int **resultMatrix = create2dMatrix(mergedRows, cols1);
    
    convertTo2D(mergedArr, resultMatrix, mergedRows, cols1);
    
    printf("\nMerged and Sorted Result Matrix:\n");
    printMatrix(resultMatrix, mergedRows, cols1);
    
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(resultMatrix, mergedRows);
    free(arr1);
    free(arr2);
    free(mergedArr);
    
    return 0;
}