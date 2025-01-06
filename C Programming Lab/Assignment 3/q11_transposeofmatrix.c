#include <stdio.h>
#include <stdlib.h>
#include "print_array.h"

int **createTransposeMatrix(int **matrix,int rows, int cols ){
    int **transpose = create2dMatrix(cols,rows);
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++){
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
    
}

int main(){
    int row,col;
    printf("Enter row of the matrix: ");
    scanf("%d",&row);

    printf("Enter col of the matrix: ");
    scanf("%d",&col);

    int **newmat = create2dMatrix(row,col);

    take2darrayInput(newmat,row,col);

    printMatrix(newmat,row,col);

    int **t = createTransposeMatrix(newmat,row,col);

    printMatrix(t,col,row);

    freeMatrix(t,col);

    freeMatrix(newmat,row);
}