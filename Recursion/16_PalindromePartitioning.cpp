// Problem: Palindrome Partitioning
// Link: https://leetcode.com/problems/palindrome-partitioning/
// Difficulty: Medium

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Time Complexity: O(2^n * n)
// Space Complexity: O(n) + O(2^n * n)

class Solution {
public:
    bool isPalindrome(string part) {
        string reversed = part;
        reverse(reversed.begin(), reversed.end());
        return part == reversed;
    }

    void getAllPartition(string s, vector<string>& partition, vector<vector<string>>& ans) {
        if(s.empty()) {
            ans.push_back(partition);
            return;
        }

        for(int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if(isPalindrome(part)) {
                partition.push_back(part);
                getAllPartition(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> partition;
        vector<vector<string>> ans;
        getAllPartition(s, partition, ans);
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string>> result = solution.partition(s);

    for(const auto& partition : result) {
        for(const string& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
