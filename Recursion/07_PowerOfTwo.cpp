// Problem: Power of Two using
// Link: https://leetcode.com/problems/power-of-two/
// Difficulty: Easy

#include <iostream>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(log n)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 2 != 0) return false;
        return isPowerOfTwo(n / 2);
    }
};

int main() {
    Solution obj;

    int test1 = 16;
    int test2 = 18;
    int test3 = 1;

    cout << "Is " << test1 << " a power of two? " << (obj.isPowerOfTwo(test1) ? "Yes" : "No") << endl;
    cout << "Is " << test2 << " a power of two? " << (obj.isPowerOfTwo(test2) ? "Yes" : "No") << endl;
    cout << "Is " << test3 << " a power of two? " << (obj.isPowerOfTwo(test3) ? "Yes" : "No") << endl;

    return 0;
}
