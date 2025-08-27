// Problem: Daily Temperatures
// Link: https://leetcode.com/problems/daily-temperatures/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            
            if(!st.empty()) {
                ans[i] = st.top() - i;
            }
            
            st.push(i);
        }
        
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    
    vector<int> result = obj.dailyTemperatures(temperatures);
    cout << "Input: ";
    for(int temp : temperatures) cout << temp << " ";
    cout << endl << "Output: ";
    for(int res : result) cout << res << " ";
    cout << endl;
    
    return 0;
}
