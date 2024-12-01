#include <stdio.h>

int main(){
    int a,b,c; // Declare 3 variables for average
    float result; // Storing Average in Float
    printf("Enter Three Numbers to find Average\n");
    scanf("%d%d%d",&a,&b,&c);

    // Calculating average of three numbers and typecasting into float
    result = (float)(a+b+c)/3.00;
    printf("Average of %d,%d and %d is : %.2f\n",a,b,c,result);
    return 0;
}
