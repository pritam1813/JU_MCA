#include <iostream>
using namespace std;

class ExampleConstructor
{
    int *loc;

public:
    ExampleConstructor()
    {
        loc = new int(4);
        cout << "Address in Main Constructor: " << loc << endl;
    }
    ExampleConstructor(int n)
    {
        loc = new int(n);
        cout << "Parameterized Constructor: " << loc << endl;
    }
    ExampleConstructor(const ExampleConstructor &obj1)
    {
        cout << "Address in Copy Constructor: " << obj1.loc << endl;
    }
    ~ExampleConstructor()
    {
        delete loc;
    }
};

class Parent
{
public:
    Parent()
    {
        cout << "Parent Class Constructor called" << endl;
    }
    virtual ~Parent()
    {
        cout << "Parent Class Destructor called" << endl;
    }
};

class Derived : public Parent
{
public:
    Derived()
    {
        cout << "Derived Class Constructor called" << endl;
    }
    ~Derived()
    {
        cout << "Derived Class Destructor called" << endl;
    }
};

int main()
{
    ExampleConstructor c1;
    ExampleConstructor c2(c1);
    ExampleConstructor c3(5);

    Derived *d = new Derived();
    Parent *p = d;
    delete p;
}