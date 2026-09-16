#include <iostream>
using namespace std;
bool searchMatrix(int matrix[][4], int rows, int cols, int target){
    int left = 0;
    int right = rows * cols - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == target){
            return true;
        }
        else if (matrix[row][col] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        } }
    return false;
}
int main()
{
    int matrix[3][4] ={
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60} };
    int target;
    cout << "Enter target: ";
    cin >> target;
    if (searchMatrix(matrix, 3, 4, target)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}