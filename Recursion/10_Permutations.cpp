// Problem: 46. Permutations
// Link: https://leetcode.com/problems/permutations/
// Difficulty: Medium

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n * n!)
// Space Complexity: O(n * n!)

class Solution {
public:
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPerms(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = obj.permute(nums);

    cout << "All permutations:\n";
    for (auto perm : result) {
        cout << "[ ";
        for (int num : perm) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
