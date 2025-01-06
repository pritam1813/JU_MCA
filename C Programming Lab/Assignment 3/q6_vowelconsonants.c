#include <stdio.h>

int findNumberOfVowels(char *str)
{
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            count++;
    }
    return count;
}

int findNumberOfConsonants(char *str)
{
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != ' ')
            count++;
    }
    return count;
}

int main()
{
    printf("Enter a string: ");
    char str[100];
    scanf("%[^\n]s", str);
    int vowels, consonants;
    vowels = findNumberOfVowels(str);
    printf("Vowels: %d\n", vowels);
    consonants = findNumberOfConsonants(str);
    printf("Consonants: %d\n", consonants);
}