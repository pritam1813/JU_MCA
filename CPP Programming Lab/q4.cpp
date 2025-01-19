#include <iostream>
using namespace std;

class Pattern
{
    int n;

public:
    Pattern(int n)
    {
        this->n = n;
    }

    void displayPattern()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < (2 * (n - i) - 1); j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    Pattern *p = new Pattern(n);
    p->displayPattern();
    delete p;

    return 0;
}
