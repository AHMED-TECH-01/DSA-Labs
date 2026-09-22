#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class CircularQueue
{
private:
    Node* rear;

public:

    CircularQueue()
    {
        rear = NULL;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if (rear == NULL)
        {
            rear = newNode;
            rear->next = rear;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " inserted." << endl;
    }

    void dequeue()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* front = rear->next;

        if (front == rear)
        {
            rear = NULL;
        }
        else
        {
            rear->next = front->next;
        }

        cout << front->data << " removed." << endl;
        delete front;
    }

    void display()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* front = rear->next;
        Node* current = front;

        cout << "Queue: ";

        do
        {
            cout << current->data << " ";
            current = current->next;
        }
        while (current != front);

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    q.enqueue(40);

    q.display();

    return 0;
}