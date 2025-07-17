// Problem: Max Consecutive Ones
// Link: https://leetcode.com/problems/max-consecutive-ones/
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 1) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }

    return maxCount;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int result = findMaxConsecutiveOnes(nums);

    cout << "Maximum Consecutive Ones: " << result << endl;

    return 0;
}
