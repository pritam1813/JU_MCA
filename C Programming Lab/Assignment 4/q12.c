#include <stdio.h>

void searchStringInAstring(char *a, char *b){
    int i=0,j=0;
    while (a[i] != '\0')
    {
        if(a[i] == b[j]){
            
            j++;
        }

        i++;
    }
    
}

int main(){
    
    // printf("Enter a string: ");
    char a[] = "This is a string";
    char b[] = "a s";
    searchStringInAstring(a,b);
}