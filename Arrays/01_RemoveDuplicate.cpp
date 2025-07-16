// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};

    int newLength = removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
