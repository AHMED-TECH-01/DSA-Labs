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

class Stack
{
private:
    Node* top;

public:

    Stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;

        cout << value << " pushed." << endl;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;

        cout << top->data << " popped." << endl;

        top = top->next;

        delete temp;
    }
    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Top = " << top->data << endl;
    }F
    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;

        cout << "Stack: ";

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
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

    s.peek();

    return 0;
}