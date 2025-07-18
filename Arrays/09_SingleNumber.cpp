// Problem: Single Number  
// Link: https://leetcode.com/problems/single-number/  
// Difficulty: Easy  

#include <iostream>  
#include <vector>  
using namespace std;  

// Time Complexity: O(n)  
// Space Complexity: O(1)  

int singleNumber(vector<int>& nums) {
    int xor1 = 0;
    for(int i = 0; i < nums.size(); i++) {
        xor1 ^= nums[i];
    }
    return xor1;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    int result = singleNumber(nums);

    cout << "Single Number: " << result << endl;

    return 0;
}
