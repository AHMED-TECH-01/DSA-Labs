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

class DoublyList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int x)
    {
        Node* newNode = new Node(x);

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

    void sortDescending()
    {
        Node* i = head;

        while (i != NULL)
        {
            Node* j = i->next;

            while (j != NULL)
            {
                if (i->data < j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }

                j = j->next;
            }

            i = i->next;
        }
    }
};

int main()
{
    DoublyList L;
 
    for (int i = 1; i <= 10; i++)
    {
        L.insert(i);
    }
    L.sortDescending();
    cout << "N in descending order: ";
    L.display();

    return 0;
}