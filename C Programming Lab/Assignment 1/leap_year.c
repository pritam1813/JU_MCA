#include <stdio.h>

int main()
{
    int year;
    printf("Enter a year\n");
    scanf("%d", &year);

    year % 4 == 0 || year % 400 == 0 && year % 100 != 0 ? printf("Leap Year") : printf("Not a Leap year");

    return 0;
}