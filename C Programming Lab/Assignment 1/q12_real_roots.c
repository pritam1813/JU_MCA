#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);

    double discriminant = (b * b) - (4 * a * c);

    double root1, root2, root3;
    double denominator = 2 * a;

    if (discriminant > 0)
    {
        root1 = -b + sqrt(discriminant) / denominator;
        root2 = -b - sqrt(discriminant) / denominator;

        printf("The roots of Equation %.2lfx^2 + %.2flfd + %.2flfc = 0 are : %.2flf and %.2flf /n", a, b, c, root1, root2);
    }

    if (discriminant = 0)
    {
        root1 = -(b / denominator);

        printf("The both roots of Equation %.2flfx^2 + %.2flfd + %.2flfc = 0 are same i.e. %.2flf/n", a, b, c, root1);
    }

    if (discriminant < 0)
    {
        double realPart = -b / denominator;
        double imagPart = sqrt(-discriminant);

        printf("The roots of Equation %.2flfx^2 + %.2flfd + %.2flfc = 0 are : %.2flf and %.2flf /n", a, b, c, realPart, imagPart);
    }
}