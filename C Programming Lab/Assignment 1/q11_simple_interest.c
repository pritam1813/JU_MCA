#include <stdio.h>

int main()
{
    float principle, rate, time, interest;

    printf("Enter principle\n");
    scanf("%f", &principle);
    printf("Enter rate\n");
    scanf("%f", &rate);
    printf("Enter time\n");
    scanf("%f", &time);

    interest = (principle * rate * time) / 100.00;

    printf("Interest is %.2f\n", interest);

    return 0;
}