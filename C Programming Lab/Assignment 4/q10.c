#include <stdio.h>
#include <math.h>

void converttobaseb(int, int);
void converttobaseb_float(float, int);

int main()
{
    float x;
    int b;
    printf("Enter Decimal Number: ");
    scanf("%f", &x);
    printf("Enter Base to convert to: ");
    scanf("%d", &b);
    int int_part = (int)x;
    float frac_part = x - int_part;
    converttobaseb(int_part, b);
    if (frac_part > 0)
    {
        printf(".");
        converttobaseb_float(frac_part, b);
    }
    printf("\n");
    return 0;
}

void converttobaseb(int x, int b)
{
    if (x == 0)
    {
        return;
    }
    int remainder = x % b;
    converttobaseb(x / b, b);
    if (b == 16 && remainder >= 10)
    {
        printf("%c", 'A' + (remainder - 10));
    }
    else
    {
        printf("%d", remainder);
    }
}

void converttobaseb_float(float x, int b)
{
    int count = 0;
    while (x > 0 && count < 6)
    {
        x *= b;
        int int_part = (int)x;
        if (b == 16 && int_part >= 10)
        {
            printf("%c", 'A' + (int_part - 10));
        }
        else
        {
            printf("%d", int_part);
        }
        x -= int_part;
        count++;
    }
}
