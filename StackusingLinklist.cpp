#include <iostream>
using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Stack Class
class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = NULL;
    }

    // Push
    void push(int val)
    {
        Node* newNode = new Node(val);

        newNode->next = top;
        top = newNode;

        cout << val << " pushed\n";
    }

    // Pop
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped\n";

        top = top->next;
        delete temp;
    }

    // Peek
    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
        }
        else
        {
            cout << "Top element: " << top->data << endl;
        }
    }

    // Display
    void display()
    {
        Node* temp = top;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();

    s.display();

    return 0;
}
