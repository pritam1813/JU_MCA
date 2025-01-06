#include <stdio.h>
#include <math.h>

#define NTHFIB 9
#define A 56
#define B 98

int FiboncciNumber(int);
int GCD(int, int);
int fact(int);
int reverse(int);
int sumofdigits(int);
int divisor(int, int);

int main()
{
    int nthFact = 3, revDigit = 12345, digitssum = 7823, div = 101;

    printf("The %dth Fibonacci Number is:- %d\n", NTHFIB, FiboncciNumber(NTHFIB));
    printf("The GCD of two numbers %d and %d is: %d\n", A, B, GCD(A, B));
    printf("Factorial of %d is: %d\n", nthFact, fact(nthFact));
    printf("Reverse of %d is %d\n", revDigit, reverse(revDigit));
    printf("Sum of %d's digits is %d\n", digitssum, sumofdigits(digitssum));
    printf("Largest divisor of %d is: %d\n", div, divisor(div, div / 2));
    return 0;
}

// a. Fibonacci

int FiboncciNumber(int nth)
{
    if (nth == 1)
    {
        return 0;
    }
    if (nth == 2)
    {
        return 1;
    }

    return (FiboncciNumber(nth - 1) + FiboncciNumber(nth - 2));
}

// b. GDC of two
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

// c. Factorial
int fact(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return n * fact(n - 1);
}

// d.Reverse of a number
int reverse(int n)
{
    if (!n)
    {
        return 0;
    }

    return ((n % 10) * pow(10, (int)log10(n)) + reverse(n / 10));
}

// e. Sum of digits of a number
int sumofdigits(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return (n % 10) + sumofdigits(n / 10);
}

// f. divisor of a number
int divisor(int n, int a)
{
    if (n % a == 0)
    {
        return a;
    }
    return divisor(n, a - 1);
}
