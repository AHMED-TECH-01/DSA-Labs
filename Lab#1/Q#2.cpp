#include <iostream>
using namespace std;
int main()
{
    int st = 5;
    int sub = 5;
    string names[st] = {
        "Ali",
        "Hiba",
        "Asma",
        "Zain",
        "Faisal"
    };
    double grades[st][sub] = {
        {3.66, 3.33, 4.00, 3.00, 2.66},
        {3.33, 3.00, 3.66, 3.00, -1},
        {4.00, 3.66, 2.66, -1, -1},
        {2.66, 2.33, 4.00, -1, -1},
        {3.33, 3.66, 4.00, 3.00, 3.33}
    };
    for (int i = 0; i < st; i++)
    {
        double total = 0;
        int count = 0;

        for (int j = 0; j < sub; j++)
        {
            if (grades[i][j] != -1)
            {
                total += grades[i][j];
                count++;
            }
        }
        double GPA = total / count;

        cout << names[i] << " GPA = " << GPA << endl;
    }
    return 0;
}