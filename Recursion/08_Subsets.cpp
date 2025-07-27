// Problem: 78. Subsets
// Link: https://leetcode.com/problems/subsets/
// Difficulty: Medium

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(n * 2^n)

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);
        ans.pop_back();
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = obj.subsets(nums);

    cout << "All subsets:\n";
    for (auto subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
