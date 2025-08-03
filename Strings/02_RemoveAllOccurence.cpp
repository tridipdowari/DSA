// Problem: Remove All Occurrences of a Substring  
// Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/  
// Difficulty: Easy

#include <iostream>
#include <string>
using namespace std;

// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        for (char ch : s) {
            result += ch;

            if (result.size() >= part.size() &&
                result.substr(result.size() - part.size()) == part) {
                result.erase(result.size() - part.size());
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    string s = "daabcbaabcbc";
    string part = "abc";

    cout << solution.removeOccurrences(s, part) << endl;  // Output: dab

    return 0;
}
