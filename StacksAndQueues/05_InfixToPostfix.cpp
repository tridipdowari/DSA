// Problem: Infix to Postfix
// Link: https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    int prec(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

  public:
    string infixToPostfix(string& s) {
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || 
                (s[i] >= 'a' && s[i] <= 'z') || 
                (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
            }
            else if (s[i] == '(') {
                st.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else { // operator
                while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

// Driver code (for testing locally)
int main() {
    Solution obj;
    string expression = "a+b*(c^d-e)^(f+g*h)-i";  

    string result = obj.infixToPostfix(expression);
    cout << "Infix Expression: " << expression << endl;
    cout << "Postfix Expression: " << result << endl;

    return 0;
}
