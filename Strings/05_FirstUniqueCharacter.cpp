// Problem: First Unique Character in a String
// Link: https://leetcode.com/problems/first-unique-character-in-a-string/
// Difficulty: Easy

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            if (freq[s[i]] == 1) q.push(i);
            while (!q.empty() && freq[s[q.front()]] > 1) q.pop();
        }

        return q.empty() ? -1 : q.front();
    }
};

int main() {
    Solution solution;

    string input1 = "leetcode";
    string input2 = "loveleetcode";
    string input3 = "aabb";

    cout << "Input: " << input1 << "\nOutput: " << solution.firstUniqChar(input1) << "\n\n";
    cout << "Input: " << input2 << "\nOutput: " << solution.firstUniqChar(input2) << "\n\n";
    cout << "Input: " << input3 << "\nOutput: " << solution.firstUniqChar(input3) << "\n";

    return 0;
}
