#include <stdio.h>
#include <conio.h>

int main()
{
    int choice, num;
    char ch;
    double tem;
    do
    {
        printf("\nTemperature Conversion Menu:");
        printf("\n1. Centigrade to Farenheit");
        printf("\n2. Farenheit to Celcius");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Temperature in Farenheit: ");
            scanf("%lf", &tem);
            printf("\nTemperature in Celcius: %.2lf", ((5.0 / 9.0) * (tem - 32.00)));
            break;
        case 2:
            printf("\nEnter Temperature in Celcius: ");
            scanf("%lf", &tem);
            printf("\nTemperature in Farenheit: %.2lf", ((tem * (9.0 / 5.0)) + 32.00));
            break;
        case 3:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice! Please try again.");
        }

        printf("\nPress any key to continue...");
        ch = getch();
    } while (choice != 3);

    return 0;
}
