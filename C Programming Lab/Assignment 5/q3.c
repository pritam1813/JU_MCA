#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 50

typedef struct
{
    long int account_no;
    char name[L];
    float balance;
} bank_customer;

void get_customer_with_low_deposit(bank_customer *, int);
void get_customer_input(bank_customer *, int);

int main()
{
    int customers;
    printf("Enter number of customer: ");
    scanf("%d", &customers);
    getchar();

    bank_customer *b1 = malloc(customers * sizeof(bank_customer));
    if (b1 == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    get_customer_input(b1, customers);
    get_customer_with_low_deposit(b1, customers);

    free(b1);
    return 0;
}

void get_customer_with_low_deposit(bank_customer *b, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (b[i].balance <= 1000.00)
        {
            printf("----\t\t----\n");
            printf("Customer %d\n", i + 1);
            printf("Name: %s\nAccount Number: %ld\nBalance: %.2f\n",
                   b[i].name, b[i].account_no, b[i].balance);
            printf("----\t\t----\n");
        }
    }
}

void get_customer_input(bank_customer *b, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter Customer %d Name: ", i + 1);
        scanf("%[^\n]", b[i].name);
        getchar();

        printf("Enter Account Number: ");
        scanf("%ld", &b[i].account_no);
        getchar();

        printf("Enter Balance: ");
        scanf("%f", &b[i].balance);
        getchar();
    }
}