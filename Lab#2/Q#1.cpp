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

Node* mergeLists(Node* list1, Node* list2)
{
    Node temp(0);
    Node* current = &temp;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            current->next = list1;
            list1 = list1->next;
        }
        else
        {
            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }
    if (list1 != NULL)
        current->next = list1;
    else
        current->next = list2;

    return temp.next;
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
    Node* l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = new Node(4);
    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);
    Node* merged = mergeLists(l1, l2);
    cout << "Merged List: ";
    display(merged);
    return 0;
}