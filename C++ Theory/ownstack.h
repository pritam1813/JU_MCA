#include <iostream>
#include "node.h"
using namespace std;

class CStack
{
public:
    Node *top;
    CStack()
    {
        top = nullptr;
    }
    ~CStack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }
    void push(int);
    void pop();
    void peek();
    void display();
};

void CStack::push(int data)
{
    Node *n = new Node(data);
    if (top == nullptr)
    {
        top = n;
    }
    else
    {
        n->next = top;
        top = n;
    }
}

void CStack::pop()
{
    if (top == nullptr)
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void CStack::peek()
{
    if (top != nullptr)
    {
        cout << "Top element: " << top->data << endl;
    }
    else
    {
        cout << "Stack is Empty" << endl;
    }
}

void CStack::display()
{
    if (top == nullptr)
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    Node *temp = top;
    cout << "Stack contents: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
