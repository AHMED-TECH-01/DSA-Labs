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

Node* removeDuplicates(Node* head)
{
    Node* current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);

    cout << "Original List: ";
    display(head);

    head = removeDuplicates(head);

    cout << "\nAfter Removing Duplicates: ";
    display(head);

    return 0;
}