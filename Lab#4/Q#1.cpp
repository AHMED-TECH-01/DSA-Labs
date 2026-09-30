#include <iostream>
using namespace std;

class Stack
{
private:
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char value)
    {
        arr[++top] = value;
    }

    void pop()
    {
        top--;
    }

    char peek()
    {
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }

    bool palindrome(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            push(s[i]);
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != peek())
            {
                return false;
            }

            pop();
        }

        return true;
    }
};

int main()
{
    Stack st;
    string s;

    cout << "Enter string: ";
    cin >> s;

    if (st.palindrome(s))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}