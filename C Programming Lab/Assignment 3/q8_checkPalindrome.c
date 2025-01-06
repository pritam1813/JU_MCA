#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindrome(char *str)
{
    int i = 0, j = strlen(str) - 1;
    char *temp = malloc(sizeof(char) * strlen(str));
    strcpy(temp, str);
    while (i < j)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
    return strcmp(temp, str);
}

int main()
{

    printf("Enter a string: ");
    char str[100];
    scanf("%[^\n]s", str);

    palindrome(str) != 0 ? printf("Not a palindrome\n") : printf("Is a palindrome\n");
    printf("%s\n", str);
}