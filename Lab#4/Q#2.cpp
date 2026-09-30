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
        if (top != -1)
            top--;
    }

    bool empty()
    {
        return top == -1;
    }

    bool compare(string s, string t)
    {
        Stack s1;
        Stack s2;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                s1.pop();
            }
            else
            {
                s1.push(s[i]);
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == '#')
            {
                s2.pop();
            }
            else
            {
                s2.push(t[i]);
            }
        }

        if (s1.top != s2.top)
            return false;

        for (int i = 0; i <= s1.top; i++)
        {
            if (s1.arr[i] != s2.arr[i])
                return false;
        }

        return true;
    }
};

int main()
{
    Stack st;

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (st.compare(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}