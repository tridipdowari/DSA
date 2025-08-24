// Problem: Min Stack
// Link: https://leetcode.com/problems/min-stack/
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1) for all operations
// Space Complexity: O(n)

class MinStack {
public:
    stack<long long int> s;
    long long int minVal;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal = val;
        } else {
            if(val < minVal){
                s.push((long long)2 * val - minVal);
                minVal = val;
            }
            else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top() < minVal){
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < minVal){
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl; // -3
    obj->pop();
    cout << obj->top() << endl;    // 0
    cout << obj->getMin() << endl; // -2
    return 0;
}
