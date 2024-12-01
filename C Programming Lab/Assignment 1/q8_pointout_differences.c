#include <stdio.h>

int main(){
    int code = 4;
    /*
    if(code == 4)printf("bonus\n"); // Compairing
    else printf("penalty\n");
    */
    
    if(code = 4)printf("bonus\n"); // Not compairing just asignning
    else printf("penalty\n");
    
    return 0;
}