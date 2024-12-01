#include <stdio.h>

int main(){
    int a;
    printf("Enter a Number\n");
    scanf("%d",&a);

    a % 2 == 0 ? printf("Even\n") : printf("Odd\n");
}