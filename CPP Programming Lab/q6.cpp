#include <iostream>
using namespace std;

class LeapYearCheck
{
    int year;

public:
    LeapYearCheck(int year)
    {
        this->year = year;
    }
    ~LeapYearCheck()
    {
        if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
        {
            cout << "Not a leap year";
        }
        else
        {
            cout << "It is a leap year";
        }
    }
};

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;
    LeapYearCheck *l = new LeapYearCheck(year);
    delete l;
}