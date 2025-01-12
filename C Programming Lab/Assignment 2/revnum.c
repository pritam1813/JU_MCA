#include<stdio.h>

int reversenum(int n)
{
    int reverse = 0;
    
    while (n != 0){
        reverse *= 10;
        reverse += (n % 10);
        n /= 10;
    }
    
    return reverse;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("\nReverse of the number %d is %d",n,reversenum(n));
    printf("\n%d is ",n);
    n == reversenum(n) ? printf("") : printf("not ");
    printf("a palindrome");
    return 0;
}