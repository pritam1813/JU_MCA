#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchString(char *mainStr, char *searchStr)
{
    int mainLen = strlen(mainStr);
    int searchLen = strlen(searchStr);

    if (searchLen > mainLen)
    {
        return 0;
    }

    for (int i = 0; i <= mainLen - searchLen; i++)
    {
        int j;
        for (j = 0; j < searchLen; j++)
        {
            if (mainStr[i + j] != searchStr[j])
            {
                break;
            }
        }
        if (j == searchLen)
        {
            return i + 1;
        }
    }

    return 0;
}

int main()
{
    char *str1, *str2;
    int len1, len2;

    printf("Enter length of first string: ");
    scanf("%d", &len1);
    getchar();

    str1 = (char *)malloc((len1 + 1) * sizeof(char));

    printf("Enter first string: ");
    fgets(str1, len1 + 1, stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter length of second string: ");
    scanf("%d", &len2);
    getchar();

    str2 = (char *)malloc((len2 + 1) * sizeof(char));

    printf("Enter second string: ");
    fgets(str2, len2 + 1, stdin);
    str2[strcspn(str2, "\n")] = 0;

    int position = searchString(str1, str2);

    if (position == 0)
    {
        printf("\nString '%s' not found in '%s'\n", str2, str1);
    }
    else
    {
        printf("\nString '%s' found at position %d in '%s'\n", str2, position, str1);
    }

    free(str1);
    free(str2);

    return 0;
}