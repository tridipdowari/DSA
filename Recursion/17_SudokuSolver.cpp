// Problem: Sudoku Solver
// Link: https://leetcode.com/problems/sudoku-solver/
// Difficulty: Hard

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(9^E), where E is the number of empty cells
// Space Complexity: O(1), modifies board in-place using backtracking

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Check row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == dig) return false;
        }

        // Check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == dig) return false;
        }

        // Check 3x3 subgrid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for(int i = srow; i < srow + 3; i++) {
            for(int j = scol; j < scol + 3; j++) {
                if(board[i][j] == dig) return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        if(row == 9) return true;

        int nextRow = row, nextCol = col + 1;
        if(nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if(board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        for(char dig = '1'; dig <= '9'; dig++) {
            if(isSafe(board, row, col, dig)) {
                board[row][col] = dig;
                if(helper(board, nextRow, nextCol)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};

// Optional: main() for local testing
int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solution.solveSudoku(board);

    for(const auto& row : board) {
        for(char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
