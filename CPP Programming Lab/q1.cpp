#include <iostream>
using namespace std;

#define PI 3.14

class Circle
{
    double radius;

protected:
    double area;

public:
    Circle(float radius)
    {
        this->radius = radius;
    }
    double getRadius()
    {
        return radius;
    }
};

class AreaOfCircle : public Circle
{
public:
    AreaOfCircle(float radius) : Circle(radius) {}
    void printAreaofCircle()
    {
        double r = getRadius();
        area = PI * r * r;
        cout << "Area of circle with radius " << r << " is " << area << endl;
    }
};

int main()
{
    float r;
    cout << "Enter Radius of the circle: " << endl;
    cin >> r;
    AreaOfCircle *a = new AreaOfCircle(r);
    a->printAreaofCircle();
}