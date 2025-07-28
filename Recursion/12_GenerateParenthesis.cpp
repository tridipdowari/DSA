// Problem: Generate Parentheses  
// Link: https://leetcode.com/problems/generate-parentheses/  
// Difficulty: Medium  

#include <iostream>  
#include <vector>  
using namespace std;  

// Time Complexity: O(2^n * n)  
// Space Complexity: O(2^n * n)

class Solution {
public:
    void generate(int open, int close, int n, string current, vector<string>& ans) {
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        if (open < n)
            generate(open + 1, close, n, current + '(', ans);

        if (close < open)
            generate(open, close + 1, n, current + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0, 0, n, "", ans);
        return ans;
    }
};

int main() {
    Solution obj;
    int n = 3;

    vector<string> result = obj.generateParenthesis(n);
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
