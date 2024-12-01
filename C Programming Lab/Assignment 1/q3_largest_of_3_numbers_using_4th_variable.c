#include <stdio.h>

int main()
{
    int a, b, c, res; // Declare 3 variables to find largest number
    printf("Enter Three Numbers to find Largest number\n");
    scanf("%d%d%d", &a, &b, &c); // Taking input from user

    a > b ? (res = a) : (res = b); // Compairing largest between a and b and storing it in res
    
    if(res < c){
        res = c; // compairing largest between res and c  and updating res if c is larger
    }

    printf("The Largest of three numbers %d, %d and %d is: %d\n",a,b,c,res);
}