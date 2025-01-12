#include <stdio.h>
#include <string.h>

const char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

void twoDigitToWords(int num, char *words)
{
    if (num < 10)
    {
        strcat(words, ones[num]);
    }
    else if (num < 20)
    {
        strcat(words, teens[num - 10]);
    }
    else
    {
        strcat(words, tens[num / 10]);
        if (num % 10 != 0)
        {
            strcat(words, " ");
            strcat(words, ones[num % 10]);
        }
    }
}

void toIndianWords(int num, char *words)
{
    if (num == 0)
    {
        strcpy(words, "Zero");
        return;
    }

    int crore = num / 10000000;
    int lakh = (num / 100000) % 100;
    int thousand = (num / 1000) % 100;
    int hundred = (num / 100) % 10;
    int last_two = num % 100;

    if (crore > 0)
    {
        twoDigitToWords(crore, words);
        strcat(words, " Crore ");
    }

    if (lakh > 0)
    {
        twoDigitToWords(lakh, words);
        strcat(words, " Lakh ");
    }

    if (thousand > 0)
    {
        twoDigitToWords(thousand, words);
        strcat(words, " Thousand ");
    }

    if (hundred > 0)
    {
        strcat(words, ones[hundred]);
        strcat(words, " Hundred ");
        if (last_two > 0)
            strcat(words, "and ");
    }

    if (last_two > 0)
    {
        twoDigitToWords(last_two, words);
    }
}

void toInternationalWords(int num, char *words)
{
    if (num == 0)
    {
        strcpy(words, "Zero");
        return;
    }

    int millions = num / 1000000;
    int thousands = (num / 1000) % 1000;
    int hundreds = num % 1000;

    if (millions > 0)
    {
        twoDigitToWords(millions, words);
        strcat(words, " Million ");
    }

    if (thousands > 0)
    {
        if (thousands >= 100)
        {
            strcat(words, ones[thousands / 100]);
            strcat(words, " Hundred ");
            if (thousands % 100 > 0)
                strcat(words, "and ");
        }
        if (thousands % 100 > 0)
        {
            twoDigitToWords(thousands % 100, words);
        }
        strcat(words, " Thousand ");
    }

    if (hundreds > 0)
    {
        if (hundreds >= 100)
        {
            strcat(words, ones[hundreds / 100]);
            strcat(words, " Hundred ");
            if (hundreds % 100 > 0)
                strcat(words, "and ");
        }
        if (hundreds % 100 > 0)
        {
            twoDigitToWords(hundreds % 100, words);
        }
    }
}

int main()
{
    int num;
    char indianWords[200] = "";
    char internationalWords[200] = "";

    printf("Enter an 8-digit number: ");
    scanf("%d", &num);

    if (num < 10000000 || num > 99999999)
    {
        printf("Please enter an 8-digit number only!\n");
        return 1;
    }

    toIndianWords(num, indianWords);
    toInternationalWords(num, internationalWords);

    printf("\nIndian Number System:\n");
    printf("%d = %s\n", num, indianWords);

    printf("\nInternational Number System:\n");
    printf("%d = %s\n", num, internationalWords);

    return 0;
}