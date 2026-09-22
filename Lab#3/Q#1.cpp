#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
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

    void enqueue(int x)
    {
        Node* newNode = new Node(x);

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
    }

    void dequeue()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty" << endl;
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

        delete front;
    }

    void display()
    {
        if (rear == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = rear->next;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != rear->next);

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    q.dequeue();

    cout << "After dequeue: ";
    q.display();

    return 0;
}