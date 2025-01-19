#include <iostream>
using namespace std;

class Complex
{
    int real;
    int imaginary;

public:
    Complex()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter Imaginary: ";
        cin >> imaginary;
    }
    Complex(int real)
    {
        this->real = real;
        cout << "Enter Imaginary: ";
        cin >> imaginary;
    }
    Complex(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void Show();
    Complex sum(const Complex &c1, const Complex &c2)
    {
        Complex s;
        s.real = c1.real + c2.real;
        s.imaginary = c1.imaginary + c2.imaginary;
        return s;
    }
    int getReal()
    {
        return real;
    }
    int getImaginary()
    {
        return imaginary;
    }
};

int main()
{
    int real1, real2, img1;
    Complex *c1 = new Complex();
    cout << "Enter Real part only: ";
    cin >> real1;
    Complex *c2 = new Complex(real1);

    cout << "Enter Real and imaginary: ";
    cin >> real2 >> img1;
    Complex *c3 = new Complex(real2, img1);

    c1->Show();
    c2->Show();
    c3->Show();

    Complex s;
    cout << "Sum of c1 + c2" << endl;
    cout << c1->getReal() << " + " << c1->getImaginary() << endl;
    cout << c2->getReal() << " + " << c2->getImaginary() << endl;
    cout << "--------" << endl;
    cout << s.getReal() << " + " << s.getImaginary() << endl;
}

void Complex::Show()
{
    cout << "The complex number is: " << real << " + " << imaginary << "i" << endl;
}