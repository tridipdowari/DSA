// Problem: Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty: Medium

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            string word;
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.size() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1); // remove leading space
    }
};

int main() {
    Solution solution;

    string input1 = "  the sky   is blue  ";
    string input2 = "hello world";
    string input3 = "a good   example";

    cout << "Input: \"" << input1 << "\"\nOutput: \"" 
         << solution.reverseWords(input1) << "\"\n\n";

    cout << "Input: \"" << input2 << "\"\nOutput: \"" 
         << solution.reverseWords(input2) << "\"\n\n";

    cout << "Input: \"" << input3 << "\"\nOutput: \"" 
         << solution.reverseWords(input3) << "\"\n";

    return 0;
}
