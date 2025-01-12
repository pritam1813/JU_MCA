#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class CStack
{
    Node *top;

public:
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

int main()
{
    CStack *S = new CStack();
    S->push(5);
    S->push(9);
    S->push(4);
    S->push(1);
    S->display();
    S->pop();
    S->pop();
    S->pop();
    S->peek();
    delete S;
    return 0;
}

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
