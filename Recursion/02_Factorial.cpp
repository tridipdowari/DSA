// Problem: Print Factorial using Recursion (Void Function)
// Link: https://www.geeksforgeeks.org/problems/factorial5739/1
// Difficulty: Basic

#include <iostream>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n) — due to recursion stack

class Solution {
public:
    void factorial(int n, int result = 1) {
        if (n == 0) {
            cout << result << endl;
            return;
        }
        factorial(n - 1, result * n);
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    sol.factorial(n);

    return 0;
}
