#include <stdio.h>

int main()
{
    int  n, firstd, lastd, midd;

    scanf("%d",&n);

    lastd = n % 10;
    n /= 10;
    midd = n % 10;
    n /= 10;
    firstd = n % 10;

    lastd + firstd == 2 * midd ? printf("Sum is equal to twice of middle digit\n") : printf("sum is not equals to twice of middle digit\n");
}