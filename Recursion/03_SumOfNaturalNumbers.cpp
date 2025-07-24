// Problem: Sum of first N natural numbers using recursion
// Link: https://www.codechef.com/learn/course/recursion/LRECUR01/problems/RECUR02
// Difficulty: Easy

#include <iostream>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n) — due to recursion stack

int sum(int n) {
    if(n == 1) return 1;
    
    return n + sum(n - 1);
}

int main() {
    cout << "Sum of first 5 natural numbers is " << sum(5) << endl;
    return 0;
}
