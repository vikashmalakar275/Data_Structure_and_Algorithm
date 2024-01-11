#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string Sudoku_Verifier(int (&sudoku)[9][9])
{
    for (int i=0; i<9;i++)
    {
        unordered_set<int> rowSet;
        unordered_set<int> colSet;
        unordered_set<int> boxSet;
        for (int j = 0; j < 9; ++j)
        {
            if (rowSet.count(sudoku[i][j]))
            {
                return "Not valid. Duplicate in Row " + to_string(i + 1);
            }
            rowSet.insert(sudoku[i][j]);
            if (colSet.count(sudoku[j][i])) 
            {
                return "Not valid. Duplicate in Column " + to_string(i + 1);
            }
            colSet.insert(sudoku[j][i]);
            int boxRowIndex = 3 * (i / 3);
            int boxColIndex = 3 * (i % 3);
            if (boxSet.count(sudoku[boxRowIndex + j / 3][boxColIndex + j % 3]))
            {
                return "Not valid. Duplicate in Box at Row " + to_string(i + 1) + ", Column " + to_string(j + 1);
            }
            boxSet.insert(sudoku[boxRowIndex + j / 3][boxColIndex + j % 3]);
        }
    }
    return "Valid Sudoku";
}

int main() 
{
    int sudoku[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    cout << Sudoku_Verifier(sudoku) <<endl;

    return 0;
}
