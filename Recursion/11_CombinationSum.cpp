// Problem: Combination Sum
// Link: https://leetcode.com/problems/combination-sum/
// Difficulty: Medium

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(2^target)
// Space Complexity: O(target)

class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, int index,
                          vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0 || index == candidates.size()) return;

        current.push_back(candidates[index]);
        findCombinations(candidates, target - candidates[index], index, current, result);
        current.pop_back();

        findCombinations(candidates, target, index + 1, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(candidates, target, 0, current, result);
        return result;
    }
};

int main() {
    Solution obj;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (auto& combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
