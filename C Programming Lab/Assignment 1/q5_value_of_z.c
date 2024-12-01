#include <stdio.h>

int main()
{
    int a = 5, b = 6, z;

    char c;
    do
    {
        printf("\nChoose Option \n1.z=a++ + b++ \n2.z=a++ + --b \n3.z=a++ + ++a \n0.Exit\n");
        c = getchar();

        switch (c)
        {
        case '1':
            z = a++ + b++;
            break;
        case '2':
            z = a++ + --b;
            break;
        case '3':
            z = a++ + ++a;
            break;
        default:
            break;
        }

        printf("\n\nZ = %d\n\n", z);
    } while (c != '0');

    return 0;
}