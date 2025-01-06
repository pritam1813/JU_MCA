#include <stdio.h>

int main()
{
    int choice;
    do
    {
        printf("\n#### Menu ####\n");
        printf("1.c1\n2.c2\n0.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nCase1");
            break;
        case 2:
            printf("\nCase2");
            break;
        default:
            printf("\nInvalid:");
            break;
        }
    } while (choice != 0);
}