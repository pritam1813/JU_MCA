#include <stdio.h>
#include <ctype.h>

typedef struct
{
    int vowels;
    int consonants;
} VowelsAndConsonants;

VowelsAndConsonants Vowel_Cons_Count(char *str)
{
    VowelsAndConsonants vc;
    vc.vowels = 0;
    vc.consonants = 0;
    int i = 0;

    while (str[i] != '#' && str[i] != '\0')
    {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vc.vowels++;
            }
            else
            {
                vc.consonants++;
            }
        }
        i++;
    }

    return vc;
}

int main()
{
    char str[100];
    printf("Enter a string (terminate with #): ");
    scanf("%99[^#]#", str);

    VowelsAndConsonants v = Vowel_Cons_Count(str);
    printf("The sentence has %d vowels and %d consonants.\n", v.vowels, v.consonants);

    return 0;
}
