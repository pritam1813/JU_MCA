#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
    int len = strlen(str);
    while (len--)
    {
        printf("%c", str[len]);
    }
}

void reverseRecursion(char *str, int len)
{
    if (len == 0)
    {
        return;
    }
    printf("%c", str[len - 1]);
    reverseRecursion(str, len - 1);
}

int main()
{
    char str[100];
    scanf("%[^\n]", str);
    int len = strlen(str);
    reverseRecursion(str, len);
    // printf("%s", str);
    // reverse(str);
}