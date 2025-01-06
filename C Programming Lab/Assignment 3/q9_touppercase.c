#include <stdio.h>
#include <string.h>

int main()
{

    printf("Enter a string: ");
    char str[100];
    scanf("%[^\n]s", str);
    int l = 'a' - 'A';

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= l;
        }
    }

    printf("Uppercase = %s\n", str);
}