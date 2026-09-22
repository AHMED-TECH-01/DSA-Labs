#include <iostream>
#include <vector>
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

bool isPalindrome(Node* head){
    vector<int> values;
    Node* current = head;
    while (current != NULL){
        values.push_back(current->data);
        current = current->next;
    }

    int left = 0;
    int right = values.size() - 1;

    while (left < right)
    {
        if (values[left] != values[right]){
            return false;
        }

        left++;
        right--;
    }
    return true;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    if (isPalindrome(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}