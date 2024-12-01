#include <stdio.h>

void printDigit(int n) {
    if (n == 0) {
        return;
    }
    printDigit(n / 10);
    switch (n % 10) { 
        case 1:
            printf("One ");
            break;
        case 2:
            printf("Two ");
            break;
        case 3:
            printf("Three ");
            break;
        case 4:
            printf("Four ");
            break;
        case 5:
            printf("Five ");
            break;
        case 6:
            printf("Six ");
            break;
        case 7:
            printf("Seven ");
            break;
        case 8:
            printf("Eight ");
            break;
        case 9:
            printf("Nine ");
            break;
        case 0:
            printf("Zero ");
            break;
        default:
            break;
    }
}

int main() {
    int a;

    scanf("%d", &a);

    if (a == 0) { 
        printf("Zero ");
    } else {
        printDigit(a); 
    }

    return 0;
}
