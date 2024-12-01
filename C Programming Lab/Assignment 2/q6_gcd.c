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
}

int main()
{
    int a, b;

    scanf("%d%d", &a, &b);

    printf("GCD By Euclidean is %d", euclidean(a, b));
}