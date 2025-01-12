#include <stdio.h>

int findRoomNumber(int n)
{
    if (n < 3)
    {
        return -1;
    }

    int totalSum = (n * (n + 1)) / 2;

    for (int x = 2; x < n; x++)
    {
        int leftSum = (x * (x - 1)) / 2;

        int rightSum = totalSum - leftSum - x;

        if (leftSum == rightSum)
        {
            return x;
        }
    }

    return -1;
}

int main()
{
    int n;

    printf("Enter the total number of rooms (n): ");
    scanf("%d", &n);

    int result = findRoomNumber(n);

    if (result == -1)
    {
        printf("No solution exists for n = %d\n", n);
    }
    else
    {
        printf("The professor's room number (X) is: %d\n", result);

        printf("\nVerification:\n");
        printf("Numbers to the left: ");
        for (int i = 1; i < result; i++)
        {
            printf("%d ", i);
        }

        printf("\nNumbers to the right: ");
        for (int i = result + 1; i <= n; i++)
        {
            printf("%d ", i);
        }

        int leftSum = (result * (result - 1)) / 2;
        int rightSum = (n * (n + 1)) / 2 - leftSum - result;
        printf("\nSum of left numbers: %d\n", leftSum);
        printf("Sum of right numbers: %d\n", rightSum);
    }

    return 0;
}