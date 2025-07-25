// Problem: Check if Array is Sorted using Recursion
// Link: https://www.geeksforgeeks.org/check-if-an-array-is-sorted-using-recursion/
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isSorted(vector<int>& arr) {
        return helper(arr, arr.size());
    }

    bool helper(vector<int>& arr, int n) {
        if (n == 0 || n == 1) return true;
        if (arr[n - 2] > arr[n - 1]) return false;
        return helper(arr, n - 1);
    }
};

int main() {
    Solution obj;

    vector<int> a = {1, 2, 3, 4, 5};     // Sorted
    vector<int> b = {5, 3, 1};           // Not Sorted
    vector<int> c = {7};                 // Sorted
    vector<int> d = {};                  // Sorted

    cout << "Array a: " << (obj.isSorted(a) ? "Sorted" : "Not Sorted") << endl;
    cout << "Array b: " << (obj.isSorted(b) ? "Sorted" : "Not Sorted") << endl;
    cout << "Array c: " << (obj.isSorted(c) ? "Sorted" : "Not Sorted") << endl;
    cout << "Array d: " << (obj.isSorted(d) ? "Sorted" : "Not Sorted") << endl;

    return 0;
}
