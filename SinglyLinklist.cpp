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

// Linked List Class
class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    
    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    
    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head == NULL)
            tail = NULL;

        delete temp;
    }
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
            return;
        }

        Node* temp = head;

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
    }
    
    void insert_at_pos(int val, int pos)
    {
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        if (temp == tail)
        {
            push_back(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    
    void delete_at_pos(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (pos == 0)
        {
            pop_front();
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1 && temp->next != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
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

    
    void search(int val)
    {
        Node* temp = head;
        int pos = 0;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << "Value found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Value not found\n";
    }

    
    void display()
    {
        Node* temp = head;

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
    LinkedList list;

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
