#include <stdio.h>

int main()
{
    int s1, s2, s3, s4, s5, average;
    printf("Enter Marks of 5 Subject \n");
    scanf("%d %d %d %d %d", &s1, &s2, &s3, &s4, &s5);
    average = ((s1 + s2 + s3 + s4 + s5) / 5);


    average >= 90 ? printf("Grade Obtained : A\n") : average >= 80 ? printf("Grade Obtained : B\n")
                             : average >= 70   ? printf("Grade Obtained : C\n")
                             : average >= 60   ? printf("Grade Obtained : D\n")
                             : average >= 50   ? printf("Grade Obtained : E\n")
                                              : printf("Grade Obtained : F (Failed)\n");
    return 0;
}