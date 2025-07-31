// Problem: Letter Combinations of a Phone Number  
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/  
// Difficulty: Medium  

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(4^n * n)  
// Space Complexity: O(4^n * n)

class Solution {
public:
    void getLetterCombination(string digits, int index, string output, vector<string>& ans, vector<string>& mapping) {
        if(index >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i = 0; i < value.size(); i++) {
            output.push_back(value[i]);
            getLetterCombination(digits, index + 1, output, ans, mapping);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string output;
        vector<string> ans;

        if(digits.size() <= 0) {
            return ans;
        }

        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        getLetterCombination(digits, 0, output, ans, mapping);
        return ans;
    }
};

int main() {
    Solution obj;
    string digits = "23";

    vector<string> result = obj.letterCombinations(digits);
    for(const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
