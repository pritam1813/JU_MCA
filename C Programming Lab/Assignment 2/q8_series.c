#include <stdio.h>
#include <math.h>

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

double logfunc(double x)
{
    int i;
    double res = 0;

    if (x <= -1 || x > 1)
    {
        return 0;
    }

    // Taylor series for ln(1 + x)
    for (i = 1; i <= 10; i++)
    {
        if (i % 2 == 1)
        {
            res += pow(x, i) / i;
        }
        else
        {
            res -= pow(x, i) / i;
        }
    }
    return res;
}

float sinefunc(float x)
{
    int i, j;
    float result;

    for (i = 1, j = 1; i <= 10; i++, j = j + 2)
    {
        if (i % 2 != 0)
        {
            result = result + pow(x, j) / factorial(j);
        }
        else
            result = result - pow(x, j) / factorial(j);
    }
    return result;
}

float cosfunc(float x)
{
    int i;
    float result = 1;

    for (i = 2; i <= 10; i += 2)
    {
        if (i % 2 == 0)
        {
            result -= (pow(x, i) / factorial(i));
        }
        else
        {
            result += (pow(x, i) / factorial(i));
        }
    }
    return result;
}

int main()
{
    float x;
    printf("Series A 1/1!+2/2!+...+10/10! result is : %d\n", (factorial(10 + 1) - 1));

    printf("B. Enter value of x to find Sin(x) : ");
    scanf("%f", &x);
    printf("Sine(%0.1f) upto 10 is: %0.2f\n", x, sinefunc(x * (3.14 / 180.0)));

    printf("Cos(%0.1f) upto 10 is: %0.2f\n", x, cosfunc(x * (3.142 / 180.0)));

    double lx;
    printf("Input x must be between -1 and 1 for convergence of log(1+x).\n");
    scanf("%lf", &lx);
    printf("Log(1 + %0.2lf) upto 10 is: %0.2lf\n", lx, logfunc(lx));
}