// Problem: Binary Search
// Link: https://leetcode.com/problems/binary-search/
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(1)

int binarySearch(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (target > nums[mid]) {
            start = mid + 1;
        }
        else if (target < nums[mid]) {
            end = mid - 1;
        }
        else {
            return mid; // target found
        }
    }

    return -1; // target not found
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    int target = 9;

    int index = binarySearch(nums, target);

    if (index != -1) {
        cout << "Target " << target << " found at index " << index << "." << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }

    return 0;
}
