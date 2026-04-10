#include <iostream>
using namespace std;

#define SIZE 5

int stackArr[SIZE];
int top = -1;

// Push Function
void push(int value)
{
    if (top == SIZE - 1)
    {
        cout << "Stack Overflow\n";
    }
    else
    {
        top++;
        stackArr[top] = value;
        cout << value << " pushed into stack\n";
    }
}

// Pop Function
void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow\n";
    }
    else
    {
        cout << stackArr[top] << " popped from stack\n";
        top--;
    }
}

// Peek Function
void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Top element is: " << stackArr[top] << endl;
    }
}

// Display Function
void display()
{
    if (top == -1)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();

    display();

    return 0;
}
