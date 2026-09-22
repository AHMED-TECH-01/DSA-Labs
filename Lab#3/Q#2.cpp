#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class Deque
{
private:
    Node* front;
    Node* rear;

public:
    Deque()
    {
        front = NULL;
        rear = NULL;
    }

    void insertFront(int x)
    {
        Node* newNode = new Node(x);

        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int x)
    {
        Node* newNode = new Node(x);

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront()
    {
        if (front == NULL)
        {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = front;

        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    void deleteRear()
    {
        if (rear == NULL)
        {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = rear;

        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    void display()
    {
        Node* temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Deque d;

    d.insertFront(10);
    d.insertFront(5);
    d.insertRear(20);
    d.insertRear(30);

    cout << "Deque: ";
    d.display();

    d.deleteFront();

    cout << "After deleting front: ";
    d.display();

    d.deleteRear();

    cout << "After deleting rear: ";
    d.display();

    return 0;
}