// Problem: Peak Index in a Mountain Array  
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/  
// Difficulty: Medium  

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1, end = arr.size() - 2;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid - 1] < arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, 2, 5, 3, 1};

    int result = sol.peakIndexInMountainArray(arr);
    cout << "Peak Index in Mountain Array: " << result << endl;

    return 0;
}
