#include <iostream>
using namespace std;
int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    int arr[100][100];
    int oneD[10000];
    cout << "Enter elements\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
    int k = 0;

    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            oneD[k] = arr[i][j];
            k++;
        }
    }
    cout << "\nArray:\n";

    for (int i = 0; i < k; i++)
    {
        cout << oneD[i] << " ";
    }

    return 0;
}