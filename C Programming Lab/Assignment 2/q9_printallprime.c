#include <stdio.h>

int isPrime(int a)
{
    if (a == 1 || a == 0)
    {
        return 0;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i) == 1)
        {
            printf("%d ", i);
        }
    }
}