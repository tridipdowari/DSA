// Problem: 90. Subsets II (with duplicates)
// Link: https://leetcode.com/problems/subsets-ii/
// Difficulty: Medium

#include <iostream>
#include <vector>
#include <algorithm>
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

        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[i]) idx++;

        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "All unique subsets:\n";
    for (auto subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
