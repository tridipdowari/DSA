// Problem: Fibonacci Number
// Link: https://leetcode.com/problems/fibonacci-number/
// Difficulty: Easy

#include <iostream>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(n) — due to recursion stack

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution obj;

    int n = 6;
    cout << "Fibonacci number at position " << n << " is: " << obj.fib(n) << endl;

    return 0;
}
