#include <iostream>
using namespace std;

const int MAX = 50;

void inputPuzzle(char puzzle[MAX][MAX], int rows, int cols)
{
    cout << "Enter puzzle (# for blocked cell):\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> puzzle[i][j];
}

int countHorizontalWords(char puzzle[MAX][MAX], int rows, int cols)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        int len = 0;
        for (int j = 0; j <= cols; j++)
        {
            if (j < cols && puzzle[i][j] != '#')
                len++;
            else
            {
                if (len >= 3)
                    count++;
                len = 0;
            }
        }
    }
    return count;
}

int countVerticalWords(char puzzle[MAX][MAX], int rows, int cols)
{
    int count = 0;

    for (int j = 0; j < cols; j++)
    {
        int len = 0;
        for (int i = 0; i <= rows; i++)
        {
            if (i < rows && puzzle[i][j] != '#')
                len++;
            else
            {
                if (len >= 3)
                    count++;
                len = 0;
            }
        }
    }
    return count;
}

void findLongestWord(char puzzle[MAX][MAX], int rows, int cols,
                     char longest[MAX], int &longestLen)
{
    longestLen = 0;
    char temp[MAX];

    for (int i = 0; i < rows; i++)
    {
        int k = 0;
        for (int j = 0; j <= cols; j++)
        {
            if (j < cols && puzzle[i][j] != '#')
                temp[k++] = puzzle[i][j];
            else
            {
                if (k >= 3 && k > longestLen)
                {
                    longestLen = k;
                    for (int x = 0; x < k; x++)
                        longest[x] = temp[x];
                }
                k = 0;
            }
        }
    }

    for (int j = 0; j < cols; j++)
    {
        int k = 0;
        for (int i = 0; i <= rows; i++)
        {
            if (i < rows && puzzle[i][j] != '#')
                temp[k++] = puzzle[i][j];
            else
            {
                if (k >= 3 && k > longestLen)
                {
                    longestLen = k;
                    for (int x = 0; x < k; x++)
                        longest[x] = temp[x];
                }
                k = 0;
            }
        }
    }
}

int main()
{
    char puzzle[MAX][MAX];
    char longest[MAX];
    int longestLen;
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    inputPuzzle(puzzle, rows, cols);

    cout << "\nHorizontal words count: "
         << countHorizontalWords(puzzle, rows, cols) << endl;

    cout << "Vertical words count: "
         << countVerticalWords(puzzle, rows, cols) << endl;

    findLongestWord(puzzle, rows, cols, longest, longestLen);

    if (longestLen > 0)
    {
        cout << "Longest word: ";
        for (int i = 0; i < longestLen; i++)
            cout << longest[i];
        cout << endl;
    }
    else
        cout << "No valid word found\n";

    return 0;
}
