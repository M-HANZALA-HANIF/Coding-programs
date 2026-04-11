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

// Queue Class
class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    // Enqueue (Insert)
    void enqueue(int val)
    {
        Node* newNode = new Node(val);

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << val << " inserted\n";
    }

    // Dequeue (Remove)
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " removed\n";

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    // Peek
    void peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Display
    void display()
    {
        Node* temp = front;

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
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();

    q.display();

    return 0;
}
