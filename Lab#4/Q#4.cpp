#include <iostream>
using namespace std;

bool search(char board[][4], string word,
            int row, int col, int index,
            int rows, int cols)
{
    if (index == word.length())
    {
        return true;
    }

    if (row < 0 || row >= rows ||
        col < 0 || col >= cols)
    {
        return false;
    }

    if (board[row][col] != word[index])
    {
        return false;
    }

    char temp = board[row][col];

    board[row][col] = '#';

    bool found =
        search(board, word, row + 1, col, index + 1, rows, cols) ||
        search(board, word, row - 1, col, index + 1, rows, cols) ||
        search(board, word, row, col + 1, index + 1, rows, cols) ||
        search(board, word, row, col - 1, index + 1, rows, cols);

    board[row][col] = temp;

    return found;
}

bool exist(char board[][4], string word, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == word[0])
            {
                if (search(board, word, i, j, 0, rows, cols))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    char board[3][4] =
    {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    if (exist(board, word, 3, 4))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}