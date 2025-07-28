// Problem: Rat in a Maze  
// Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1  
// Difficulty: Medium  

#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  

// Time Complexity: O(4^(n * n))  
// Space Complexity: O(n * n)

class Solution {
public:
    void helper(vector<vector<int>>& maze, int row, int col, string path, vector<string>& ans) {
        int n = maze.size();
        if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] != 1)
            return;

        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        maze[row][col] = -1;

        helper(maze, row + 1, col, path + 'D', ans);
        helper(maze, row - 1, col, path + 'U', ans);
        helper(maze, row, col + 1, path + 'R', ans);
        helper(maze, row, col - 1, path + 'L', ans);

        maze[row][col] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        helper(maze, 0, 0, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = obj.ratInMaze(maze);
    for (const string& path : result) {
        cout << path << endl;
    }

    return 0;
}
