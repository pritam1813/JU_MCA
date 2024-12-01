#include <stdio.h>
#include <stdlib.h>

int lcmofNnumbers(int *arr, int n){
    return 0;
}

int main()
{
    int n, *arr;

    printf("Enter value of n\n");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d numbers to find LCM", n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("LCM of N numbers are %d", lcmofNnumbers(arr,n));

    free(arr);
    return 0;
}