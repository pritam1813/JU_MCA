#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int dd, mm, yyyy;
} Date;

void comparedates(Date, Date);

int main()
{
    Date d1, d2;
    printf("Enter 2 Dates in format dd/mm/yyyy");
    printf("\nEnter date 1: ");
    scanf("%d/%d/%d", &d1.dd, &d1.mm, &d1.yyyy);
    getchar();
    printf("Enter date 2: ");
    scanf("%d/%d/%d", &d2.dd, &d2.mm, &d2.yyyy);
    getchar();
    comparedates(d1, d2);
}

void comparedates(Date d1, Date d2)
{
    d1.dd == d2.dd &&d1.mm == d2.mm &&d1.yyyy == d2.yyyy ? printf("\nEqual") : printf("\nUnequal");
}