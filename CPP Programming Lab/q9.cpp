#include <iostream>
using namespace std;

inline int squarenum(int n)
{
    return n * n;
}

int main()
{
    int n;
    cout << "Enter number to find square: ";
    cin >> n;
    cout << "Square of Number " << n << " is: " << squarenum(n);
}