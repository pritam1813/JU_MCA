#include <iostream>
using namespace std;

class CustomStack
{
    int *arr;
    int top;
    int capacity;

public:
    CustomStack(int n)
    {
        capacity = n;
        arr = new int[n];
        top = -1;
    }
    ~CustomStack()
    {
        delete[] arr;
    }
    // void push(int n);
    CustomStack operator+(int n);
    CustomStack operator--();
    void peek();
    void display();
};

CustomStack CustomStack::operator+(int n)
{
    if (top + 1 < capacity)
    {
        top++;
        arr[top] = n;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}

CustomStack CustomStack::operator--()
{
    if (top > -1)
    {
        top--;
    }
    else
    {
        cout << "Stack is Empty: Cannot Pop" << endl;
    }
}

void CustomStack::peek()
{
    if (top > -1)
    {
        cout << arr[top] << endl;
    }
    else
    {
        cout << "Stack is Empty" << endl;
    }
}

void CustomStack::display()
{
    if (top > -1)
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
    else
    {
        cout << "Stack is Empty" << endl;
    }
}

void stackmenu(CustomStack s)
{
    int choice;
    do
    {
        cout << "\n1.Push" << endl
             << "2.Pop" << endl
             << "3.Peek" << endl
             << "4.Display" << endl
             << "0.Exit\n\n";

        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element: ";
            int el;
            cin >> el;
            s + el;
            break;
        case 2:
            --s;
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        default:
            break;
        }
    } while (choice != 0);
}

int main()
{
    int size;
    cout << "Enter Size of Stack : ";
    cin >> size;
    CustomStack s(size);
    stackmenu(s);
}
