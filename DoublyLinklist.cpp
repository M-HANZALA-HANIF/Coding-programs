#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
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
            head->prev = newNode;
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
            newNode->prev = tail;
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

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
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
        }
        else
        {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
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
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    
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

        for (int i = 0; i < pos && temp != NULL; i++)
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
            pop_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
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

    void display_forward()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    
    void display_backward()
    {
        Node* temp = tail;

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }
};

int main()
{
    DoublyLinkedList list;

    list.push_front(10);
    list.push_front(20);
    list.push_back(30);
    list.push_back(40);

    list.display_forward();

    list.pop_front();
    list.display_forward();

    list.pop_back();
    list.display_forward();

    list.insert_at_pos(25, 2);
    list.display_forward();

    list.delete_at_pos(2);
    list.display_forward();

    list.search(30);
    list.search(100);

    cout << "Reverse: ";
    list.display_backward();

    return 0;
}
