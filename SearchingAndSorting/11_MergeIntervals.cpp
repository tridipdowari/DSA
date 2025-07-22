// Problem: Merge Intervals  
// Link: https://leetcode.com/problems/merge-intervals/  
// Difficulty: Medium  

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> merged = sol.merge(intervals);

    cout << "Merged Intervals: ";
    for (auto interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
