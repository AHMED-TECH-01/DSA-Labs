#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
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

    void insert(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void concatenate(DoublyLinkedList& other)
    {
        Node* temp = other.head;

        while (temp != NULL)
        {
            insert(temp->data);
            temp = temp->next;
        }
    }

    void sortDescending()
    {
        Node* current = head;

        while (current != NULL)
        {
            Node* temp = current->next;

            while (temp != NULL)
            {
                if (current->data < temp->data)
                {
                    int value = current->data;
                    current->data = temp->data;
                    temp->data = value;
                }

                temp = temp->next;
            }

            current = current->next;
        }
    }
};

int main()
{
    DoublyLinkedList L;
    DoublyLinkedList M;
    DoublyLinkedList N;

    for (int i = 2; i <= 10; i += 2)
    {
        L.insert(i);
    }

    for (int i = 1; i <= 9; i += 2)
    {
        M.insert(i);
    }

    cout << "List L: ";
    L.display();

    cout << "List M: ";
    M.display();

    N.concatenate(L);
    N.concatenate(M);

    cout << "List N after concatenation: ";
    N.display();

    N.sortDescending();

    cout << "List N after sorting: ";
    N.display();

    return 0;
}