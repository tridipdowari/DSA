// Problem: Missing Number  
// Link: https://leetcode.com/problems/missing-number/  
// Difficulty: Easy  

#include <iostream>  
#include <vector>  
using namespace std;  

// Time Complexity: O(n)  
// Space Complexity: O(1)  

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int totalSum = n * (n + 1) / 2;

    int currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += nums[i];
    }

    return totalSum - currSum;
}

int main() {
    vector<int> nums = {3, 0, 1};

    int result = missingNumber(nums);

    cout << "Missing Number: " << result << endl;

    return 0;
}
