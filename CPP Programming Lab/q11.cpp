#include <iostream>
using namespace std;

int reverseNumber(int num)
{
    int reversed = 0;
    while (num > 0)
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void calculate(int m, char ch)
{
    int temp = m, digitCount = 0;
    while (temp > 0)
    {
        ++digitCount;
        temp /= 10;
    }

    if (digitCount <= 1)
    {
        cout << "Error: The number must have more than one digit." << endl;
        return;
    }

    if (ch == 'r')
    {
        int reversed = reverseNumber(m);
        cout << "Reversed number: " << reversed << endl;
    }
    else if (ch == 'p')
    {
        if (isPrime(m))
        {
            cout << m << " is a prime number." << endl;
        }
        else
        {
            cout << m << " is not a prime number." << endl;
        }
    }
    else
    {
        cout << "Invalid character input. Use 'r' for reverse or 'p' for prime check." << endl;
    }
}

int main()
{
    int number;
    char option;

    cout << "Enter an integer (with more than one digit): ";
    cin >> number;
    cout << "Enter 'r' to reverse the number or 'p' to check if it is prime: ";
    cin >> option;

    calculate(number, option);
}