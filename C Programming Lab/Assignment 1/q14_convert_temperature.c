#include <stdio.h>

int main(){
    int  op;
    float temperature, result;


        printf("Choose Option \n\n1. Centigrade to  Farenheit\n2. Farenheit to Centigrade\n");
    scanf("%d",&op);

    printf("Enter temperature\n");
    scanf("%f",&temperature);

    if(op == 1){
        result = (temperature * (9/5)) + 32.00;
        printf("\nTemperature in Farenheit is: %.2f",result);
    }

    if(op == 2){
        result = (temperature - 32) * (5/9);
        printf("\nTemperature in Farenheit is: %.2f",result);

    }
}