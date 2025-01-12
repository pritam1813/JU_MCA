#include <stdio.h>

int euclidean(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return euclidean(b % a, a);
}

int primefact(int a, int b)
{
    int l = a > b ? a : b;
    int gcd = 1;
    for (int i = 1; i < l; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    printf("\nGCD By Euclidean is %d\n", euclidean(a, b));

    printf("GCD By Prime Factorization method is %d\n", primefact(a, b));
}