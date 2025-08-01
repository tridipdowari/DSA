#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string segment){
        if(segment[0] == '0'){
            return false;
        }

        int val = stoi(segment);
        return val <= 255;
    }

    void getAllIpAddress(string s, int idx, int parts, string curr, vector<string>& result){
        if(idx == s.size() && parts == 4){
            curr.pop_back(); // remove trailing dot
            result.push_back(curr);
            return;
        }

        if(idx + 1 <= s.size()){
            getAllIpAddress(s, idx + 1, parts + 1, curr + s.substr(idx, 1) + '.', result);
        } 

        if(idx + 2 <= s.size() && isValid(s.substr(idx, 2))){
            getAllIpAddress(s, idx + 2, parts + 1, curr + s.substr(idx, 2) + '.', result);
        }

        if(idx + 3 <= s.size() && isValid(s.substr(idx, 3))){
            getAllIpAddress(s, idx + 3, parts + 1, curr + s.substr(idx, 3) + '.', result);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        if(s.size() > 12){
            return result;
        }

        getAllIpAddress(s, 0, 0, "", result);
        return result;
    }
};

int main() {
    Solution solution;
    string input = "25525511135";

    vector<string> result = solution.restoreIpAddresses(input);

    for(const string& ip : result) {
        cout << ip << endl;
    }

    return 0;
}
