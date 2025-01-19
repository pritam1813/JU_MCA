#include <iostream>
#define PI 3.141592653589793
using namespace std;

double CalculateVolume(double);
double CalculateVolume(double, double, double);
double CalculateVolume(double, double);
double CalculateVolume(double, double, char);
double CalculateVolume(double, char);

int main()
{
    cout << "Find Volumes of the following:- \n\n";
    int option;
    do
    {
        cout << "1. Cube\n2. Cuboid\n3. Cone\n4. Cylinder\n5. Sphere\n0. Exit\n\n";
        cout << "Enter Option: ";
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
        {
            double side;
            cout << "Enter Side of Cube: ";
            cin >> side;
            cout << "Volume of the Cube is: " << CalculateVolume(side) << "\n\n";
            break;
        }
        case 2:
        {
            double l, b, h;
            cout << "Enter Length, Breadth, and Height (Respectively): ";
            cin >> l >> b >> h;
            cout << "Volume of the Cuboid is: " << CalculateVolume(l, b, h) << "\n\n";
            break;
        }
        case 3:
        {
            double radius, height;
            cout << "Enter Radius and Height: ";
            cin >> radius >> height;
            cout << "Volume of the Cone is: " << CalculateVolume(radius, height) << "\n\n";
            break;
        }
        case 4:
        {
            double radius, height;
            cout << "Enter Radius and Height: ";
            cin >> radius >> height;
            cout << "Volume of the Cylinder is: " << CalculateVolume(radius, height, 'c') << "\n\n";
            break;
        }
        case 5:
        {
            double radius;
            cout << "Enter Radius: ";
            cin >> radius;
            cout << "Volume of the Sphere is: " << CalculateVolume(radius, 's') << "\n\n";
            break;
        }
        default:
        {
            cout << "Invalid Choice \n\n";
            break;
        }
        }
    } while (option != 0);
}

double CalculateVolume(double side)
{
    // Cube
    return side * side * side;
}

double CalculateVolume(double length, double breadth, double height)
{
    // Cuboid
    return length * breadth * height;
}

double CalculateVolume(double baseRad, double height)
{
    // Cone
    return (PI * baseRad * baseRad * height) / 3;
}

double CalculateVolume(double baseRad, double height, char cylinder)
{
    // Cylinder
    return PI * baseRad * baseRad * height;
}

double CalculateVolume(double radius, char sphere)
{
    // Sphere
    return (4.0 / 3.0) * PI * radius * radius * radius;
}
