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

Node* merge(Node* first, Node* second)
{
    Node dummy(0);
    Node* current = &dummy;

    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            current->next = first;
            first = first->next;
        }
        else
        {
            current->next = second;
            second = second->next;
        }

        current = current->next;
    }

    if (first != NULL)
        current->next = first;
    else
        current->next = second;

    return dummy.next;
}
void split(Node* head, Node*& first, Node*& second)
{
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    first = head;
    second = slow->next;

    slow->next = NULL;
}

Node* mergeSort(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* first;
    Node* second;

    split(head, first, second);

    first = mergeSort(first);
    second = mergeSort(second);

    return merge(first, second);
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;FF
    }
}

int main()
{
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    display(head);
    head = mergeSort(head);
    cout << "\nSorted List: ";
    display(head);

    return 0;
}