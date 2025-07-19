// Problem: Linear Search
// Description: Search for a target element in an array and return its index (or -1 if not found)
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

int linearSearch(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {10, 20, 30, 40, 50};
    int target = 30;

    int index = linearSearch(nums, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
