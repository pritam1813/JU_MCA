#include <iostream>
#include <math.h>
using namespace std;

class Triangle
{
    double a, b, c;

protected:
    bool isValidTriangle(double &side1, double &side2, double &side3)
    {
        return side1 + side2 >= side3 && side1 + side3 >= side2 && side2 + side3 >= side1;
    }

public:
    void setTriangleSides()
    {
        cout << "Enter the sides of triangle" << endl;
        cin >> a >> b >> c;
        if (!isValidTriangle(a, b, c))
        {
            cout << "Invalid Triangle " << endl;
            return;
        }
    }
    double perimeter()
    {
        return a + b + c;
    }
    double area();
    void displayData();
};

double Triangle ::area()
{
    double s = (perimeter() / 2);

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::displayData()
{
    if (!isValidTriangle(a, b, c))
        return;
    cout << "Perimeter of the triangle is: " << perimeter() << endl;
    cout << "Area of the triangle is: " << area() << endl;
}

int main()
{
    Triangle T;
    T.setTriangleSides();
    T.displayData();
}