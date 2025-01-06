#include <stdio.h>

void interchangecase(char *str){
    int i =0;

    while (str[i] != '\0')
    {
        if((str[i] >= 'a') && (str[i] <= 'z')){
            str[i] = (char)(str[i] - 32);
            printf("cond A: %c\n",str[i]);
        }
        else if((str[i] >= 'A') && (str[i] <= 'Z')){
            str[i] = (char)(str[i] + 32);
            printf("cond B: %c\n",str[i]);
        }
        
        i++;
    }
    
}

int main(){
        char str[100];
    printf("Enter a string: \n");
    scanf("%[^\n]s",str);

    interchangecase(str);
    printf("%s",str);

}