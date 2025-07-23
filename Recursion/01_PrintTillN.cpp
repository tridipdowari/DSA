// Problem: Print 1 to N without using loops
// Link: https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops3621/1
// Difficulty: Easy

#include <iostream>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n) — due to recursion stack

class Solution {
public:
    void printTillN(int n) {
        if (n == 0) return;       
        printTillN(n - 1);        
        cout << n << " ";          
    }
};

int main() {
    Solution obj;
    int n = 5;

    cout << "Printing numbers from 1 to " << n << " using recursion:\n";
    obj.printTillN(n);

    return 0;
}
