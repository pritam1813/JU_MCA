#include <stdio.h>

int main(){
    int n,leftofx = 1,rightofx;

    scanf("%d",&n);
    rightofx = n;
    //roomx = (n+1) / 2;

    while (leftofx < rightofx)
    {
        
        leftofx++;
        rightofx--;
    }
    
    printf("%d",leftofx+1);
}