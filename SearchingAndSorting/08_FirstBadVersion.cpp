// Problem: First Bad Version  
// Link: https://leetcode.com/problems/first-bad-version/  
// Difficulty: Easy  

#include <iostream>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(1)

// Mock API
bool isBadVersion(int version) {
    int bad = 4; // Simulated first bad version
    return version >= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        int ans = n;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isBadVersion(mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int n = 10;
    int result = sol.firstBadVersion(n);

    cout << "First bad version: " << result << endl;

    return 0;
}
