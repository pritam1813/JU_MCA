#include <stdio.h>

void onesplace(int n)
{
    switch (n)
    {
    case 1:
        printf("One\n");
        break;
    case 2:
        printf("Two\n");
        break;
    case 3:
        printf("Three\n");
        break;
    case 4:
        printf("Four\n");
        break;
    case 5:
        printf("Five\n");
    case 6:
        printf("Six\n");
        break;
    case 7:
        printf("Seven\n");
        break;
    case 8:
        printf("Eight\n");
        break;
    case 9:
        printf("Nine\n");
        break;
    default:
        break;
    }
}

void tensplace(int n)
{
    switch (n)
    {
    case 1:
        printf("Eleven\n");
        break;
    case 2:
        printf("Twelve\n");
        break;
    case 3:
        printf("Thirteen\n");
        break;
    case 4:
        printf("Fourteen\n");
        break;
    case 5:
        printf("Fifteen\n");
    case 6:
        printf("Sixteen\n");
        break;
    case 7:
        printf("Seventeen\n");
        break;
    case 8:
        printf("Eighteen\n");
        break;
    case 9:
        printf("Nineteen\n");
        break;
    default:
        break;
    }
}

int main()
{
    int n = 121, count = 0;

    while (n != 0)
    {

        switch (++count)
        {
        case 1:
            onesplace(n % 10);
            break;
        case 2:
            tensplace(n % 10);
            break;
        default:
            break;
        }
        n /= 10;
    }
}