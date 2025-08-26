// Problem: Evaluate Reverse Polish Notation
// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        // Operator mapping with lambda functions
        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b){ return a + b; }},
            {"-", [](int a, int b){ return a - b; }},
            {"*", [](int a, int b){ return a * b; }},
            {"/", [](int a, int b){ return a / b; }}
        };

        for (string token : tokens) {
            if (mp.find(token) != mp.end()) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                int result = mp[token](a, b);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

// Driver code (for testing)
int main() {
    Solution sol;

    vector<string> tokens1 = {"2","1","+","3","*"}; 
    cout << sol.evalRPN(tokens1) << endl; // Output: 9

    vector<string> tokens2 = {"4","13","5","/","+"}; 
    cout << sol.evalRPN(tokens2) << endl; // Output: 6

    vector<string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << sol.evalRPN(tokens3) << endl; // Output: 22

    return 0;
}
