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

// Circular Linked List Class
class CircularLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Push Front
    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    // Push Back
    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // Pop Front
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    // Pop Back
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* temp = head;

            while (temp->next != tail)
            {
                temp = temp->next;
            }

            delete tail;
            tail = temp;
            tail->next = head;
        }
    }

    // Insert at Position
    void insert_at_pos(int val, int pos)
    {
        if (pos == 1)
        {
            push_front(val);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }

        if (temp->next == head && pos > 2)
        {
            push_back(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at Position
    void delete_at_pos(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1)
        {
            pop_front();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++)
        {
            temp = temp->next;
        }

        if (temp->next == head)
        {
            cout << "Invalid position\n";
            return;
        }

        if (temp->next == tail)
        {
            pop_back();
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // Search
    void search(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        int pos = 1;

        do
        {
            if (temp->data == val)
            {
                cout << "Value found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Value not found\n";
    }

    // Display
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
};

int main()
{
    CircularLinkedList list;

    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);

    list.display();

    list.pop_front();
    list.display();

    list.pop_back();
    list.display();

    list.insert_at_pos(25, 2);
    list.display();

    list.delete_at_pos(2);
    list.display();

    list.search(30);
    list.search(100);

    return 0;
}
