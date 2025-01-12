#include <stdio.h>
#include <stdlib.h>

void printarray(int *arr, int size);

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n, i, ans;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);

    printf("\nEnter Elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ans = arr[0];

    for (i = 1; i < n; i++)
    {
        ans = (ans * arr[i]) / gcd(ans, arr[i]);
    }

    printf("Lcm of elements ");

    printarray(arr, n);
    printf("is %d\n", ans);
    return 0;
}

void printarray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    // printf("\n");
}