// Problem: Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.size() == 0) return false;

                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.size() == 0;
    }
};

int main() {
    Solution solution;

    vector<string> tests = {"()", "()[]{}", "(]", "([)]", "{[]}"};

    for (string t : tests) {
        cout << "Input: " << t 
             << " -> " << (solution.isValid(t) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}
