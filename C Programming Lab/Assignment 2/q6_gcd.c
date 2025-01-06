#include <stdio.h>

int euclidean(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    if (b == 0)
    {
        return a;
    }

    return b > a ? euclidean(b % a, a) : euclidean(a % b, b);

    // Dividend = Divisor * quotient + remainder

    // int dividend, divisor, quotient, remainder, gcd = 0;

    // if (a > b)
    // {
    //     dividend = a;
    //     divisor = b;
    // }
    // else
    // {
    //     dividend = b;
    //     divisor = a;
    // }

    // remainder = dividend % divisor;
    // while (remainder != 0)
    // {
    //     printf("remainder: %d", remainder);
    //     dividend = divisor;
    //     divisor = remainder;
    //     gcd = remainder;
    //     remainder = dividend % divisor;
    // }

    // return gcd;
}

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);

    printf("GCD By Euclidean is %d", euclidean(a, b));
}