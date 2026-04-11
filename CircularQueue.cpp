#include <iostream>
using namespace std;

#define SIZE 5

int queueArr[SIZE];
int front = -1;
int rear = -1;

// Enqueue Function
void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue Overflow\n";
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queueArr[rear] = value;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        queueArr[rear] = value;
    }

    cout << value << " inserted into queue\n";
}

// Dequeue Function
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue Underflow\n";
    }
    else if (front == rear)
    {
        cout << queueArr[front] << " removed from queue\n";
        front = -1;
        rear = -1;
    }
    else
    {
        cout << queueArr[front] << " removed from queue\n";
        front = (front + 1) % SIZE;
    }
}

// Peek Function
void peek()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Front element is: " << queueArr[front] << endl;
    }
}

// Display Function
void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Queue elements are: ";

        int i = front;

        while (i != rear)
        {
            cout << queueArr[i] << " ";
            i = (i + 1) % SIZE;
        }

        cout << queueArr[rear] << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    peek();

    return 0;
}
