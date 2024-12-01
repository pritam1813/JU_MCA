#include <stdio.h>

int main()
{
    int amount, hnotes, fnotes, tnotes, onotes;
    printf("Enter Amount: ");
    scanf("%d", &amount);

    if (amount >= 100)
    {
        hnotes = amount / 100;
        amount %= 100;
        printf("Hundred Notes Required is %d\n", hnotes);
    }

    // printf("%d\n", amount);

    if (amount >= 50)
    {

        fnotes = amount / 50;
        amount %= 50;
        printf("Fifty Notes Required is %d\n", fnotes);
    }

    if (amount >= 20)
    {

        tnotes = amount / 20;
        amount %= 20;
        printf("Twenty Notes Required is %d\n", tnotes);
    }

    if (amount >= 10)
    {

        onotes = amount / 10;
        amount %= 10;
        printf("Ten Notes Required is %d\n", onotes);
    }
}