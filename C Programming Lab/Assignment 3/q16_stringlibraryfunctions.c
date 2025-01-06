#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int custom_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char *custom_strcpy(const char *src, char *dest)
{
    char *ptr = dest;
    while ((*ptr++ = *src++) != '\0')
    {
        // Copy each character
    }
    return dest;
}

char *custom_strcat(char *str1, const char *str2)
{
    char *ptr = str1;
    while (*ptr != '\0')
    {
        ptr++; 
    }
    while ((*ptr++ = *str2++) != '\0'){}
    return str1;
}

char *custom_strrev(char *str)
{
    int i = 0, j = custom_strlen(str) - 1;

    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return str;
}

int custom_strcmp(char *str1, char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Find string length\n");
    printf("2. Copy string\n");
    printf("3. Concatenate strings\n");
    printf("4. Reverse string\n");
    printf("5. Compare strings\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;
    char str[100];
    char src[100];
    char dest[100];
    char s1[100];
    char s2[100];

    while (1)
    {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Enter a string: ");
            scanf("%[^\n]",str); 
            printf("\nLength of string is: %d\n", custom_strlen(str));
            break;
        case 2:
            printf("Enter source string: ");
            scanf("%[^\n]",src);
            custom_strcpy(src, dest);
            printf("\nCopied string: %s\n", dest);
            break;
        case 3:
            printf("Enter string1: ");
            scanf("%[^\n]",s1);
            getchar();
            printf("Enter string2: ");
            scanf("%[^\n]",s2);
            getchar();
            custom_strcat(s1, s2);
            printf("\nConcatenated strings: %s\n", s1);
            break;
        case 4:
            printf("Enter a string: ");
            scanf("%[^\n]",str);
            printf("\nReversed string: %s\n", custom_strrev(str));
            break;
        case 5:
            printf("Enter string1: ");
            scanf("%[^\n]",s1);
            getchar();
            printf("Enter string2: ");
            scanf("%[^\n]",s2);
            getchar();
            printf("\nCompared result: %d\n", custom_strcmp(s1, s2));
            break;
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("\nInvalid Input\n");
            break;
        }
    }
    return 0;
}