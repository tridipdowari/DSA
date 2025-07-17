// Problem: Move Zeroes
// Link: https://leetcode.com/problems/move-zeroes/
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

void moveZeroes(vector<int>& nums) {
    int i = 0;

    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != 0) {
            nums[i] = nums[j];
            i++;
        }
    }

    while (i < nums.size()) {
        nums[i] = 0;
        i++;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
