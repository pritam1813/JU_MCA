#include <stdio.h>

char *encodetonext(char *str){
    int i =0;
    while (str[i] != '\0')
    {
        if(str[i] != ' '){
            str[i] += 1;
        }
        i++;
    }
    
    return str;
}

int main(){
    char str[100];
    printf("Enter a string: \n");
    scanf("%[^\n]s",str);

    printf("%s",encodetonext(str));
}