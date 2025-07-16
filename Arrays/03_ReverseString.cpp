// Problem: Reverse String
// Link: https://leetcode.com/problems/reverse-string/
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1) 

void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
