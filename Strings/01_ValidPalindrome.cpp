// Problem: Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome/
// Difficulty: Easy

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length() - 1;

        while (start < end) {
            // Skip non-alphanumeric characters
            if (!isalnum(s[start])) {
                start++;
                continue;
            }

            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            // Compare characters in lowercase
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};

int main() {
    Solution solution;
    
    string input1 = "A man, a plan, a canal: Panama";
