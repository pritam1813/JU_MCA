#include <stdio.h>

int powr(int n, int p)
{
    if (p <= 0)
    {
        return 1;
    }

    return n * powr(n, p - 1);
}

int main()
{

    int num, exp;

    printf("Enter Number and Power\n");
    scanf("%d%d", &num, &exp);

    printf("%d", powr(num, exp));
    return 0;
}