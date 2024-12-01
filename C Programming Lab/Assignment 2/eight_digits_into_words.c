#include <stdio.h>


int power(int num, int exp){
    if(exp == 0){
        return 1;
    }

    if(exp == 1){
        return num;
    }

    return  num * power(num,exp - 1);
}

int main(){
    int result;

    result = power(5,3);

    printf("%d",result);
}