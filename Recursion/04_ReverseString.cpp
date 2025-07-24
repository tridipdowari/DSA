// Problem: Reverse String using Recursion
// Link: https://leetcode.com/problems/reverse-string/
// Difficulty: Easy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n) — due to recursion stack

class Solution {
public:
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }

    void helper(vector<char>& s, int left, int right){
        if(left >= right) return;
        swap(s[left], s[right]);
        helper(s, left+1, right-1);
    }
};

int main() {
    Solution obj;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "Original string: ";
    for (char c : s) cout << c;
    cout << endl;

    obj.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) cout << c;
    cout << endl;

    return 0;
}
