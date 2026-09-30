#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void generate(int nums[], int start, int n)
{
    if (start == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }

        cout << endl;
        return;
    }

    for (int i = start; i < n; i++)
    {
        swap(nums[start], nums[i]);

        generate(nums, start + 1, n);

        swap(nums[start], nums[i]);
    }
}

int main()
{
    int nums[] = {1, 2, 3};
    int n = 3;

    generate(nums, 0, n);

    return 0;
}