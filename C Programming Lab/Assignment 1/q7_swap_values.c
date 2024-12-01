#include <stdio.h>

int main()
{
    int a, b, c, option;
    printf("Enter two values\n");
    scanf("%d%d", &a, &b);

    printf("Choose Option: \n1.Using third variable\n2.without using 3rd variable\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        c = a;
        a = b;
        b = c;
        break;
    case 2:
        a = a + b;
        b = a - b;
        a = a - b;
        break;
    default:
        break;
    }

    printf("Swapped Values %d and %d\n", a, b);

    return 0;
}