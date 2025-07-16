// Problem: Remove Element
// Link: https://leetcode.com/problems/remove-element/
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {3, 2, 2, 3, 4, 2, 5};
    int val = 2;

    int newLength = removeElement(nums, val);

    cout << "Array after removal: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
