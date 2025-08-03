// Problem: Valid Anagram
// Link: https://leetcode.com/problems/valid-anagram/
// Difficulty: Easy

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }

        for (char ch : t) {
            count[ch - 'a']--;
        }

        for (int val : count) {
            if (val != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";

    cout << "Input: " << s1 << ", " << t1 << "\nOutput: " 
         << (solution.isAnagram(s1, t1) ? "true" : "false") << "\n\n";

    cout << "Input: " << s2 << ", " << t2 << "\nOutput: " 
         << (solution.isAnagram(s2, t2) ? "true" : "false") << "\n";

    return 0;
}
