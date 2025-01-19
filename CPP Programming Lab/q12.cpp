#include <iostream>
#include <cstring>
using namespace std;

class OperatorOverloading
{
    char *str1;

public:
    OperatorOverloading() {}
    OperatorOverloading(char *s)
    {
        strcpy(str1, s);
    }
    OperatorOverloading operator+(OperatorOverloading const &obj)
    {
        OperatorOverloading str;
        str = strcat(str1, obj.str1);
        return str;
    }
    void getString()
    {
        cout << str1 << endl;
    }
};

// Correct later

int main()
{
    char str1[100], str2[100];
    cout << "enter a string1: ";
    cin >> str1;
    cout << "enter a string2: ";
    cin >> str2;

    OperatorOverloading o1(str1), o2(str2);
    OperatorOverloading o3;
    o3 = o1 + str2;
    o3.getString();
}