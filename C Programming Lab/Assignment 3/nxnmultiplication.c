#include <stdio.h>
#include "print_array.h"

int **multiplymatrices(int **m1, int **m2, int n)
{
    int **res = create2dMatrix(n, n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                res[i][j] += m1[i][k] * m2[k][i];
            }
        }
    }

    return res;
}

// 4 3     7 6
// 2 1     8 9

int main()
{
    int n;
    printf("Enter dimension of the square matrices: ");
    scanf("%d", &n);

    printf("Enter 1st Matrix details: \n");

    int **m1 = create2dMatrix(n, n);
    take2darrayInput(m1, n, n);

    printf("Enter 2nd Matrix details: \n");

    int **m2 = create2dMatrix(n, n);
    take2darrayInput(m2, n, n);

    printMatrix(multiplymatrices(m1, m2, n), n, n);

    freeMatrix(m1, n);
    freeMatrix(m2, n);
}