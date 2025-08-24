// Problem: Implement Stack using Arrays
// Link: https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    int arr[1000]; // Fixed-size array
    int top;       // Index of top element
public:
    MyStack() {
        top = -1;
    }

    void push(int x) {
        top++;
        arr[top] = x;
    }

    int pop() {
        if (top == -1) {
            return -1; // Stack underflow
        } else {
            int x = arr[top];
            top--;
            return x;
        }
    }
};

// Driver code (for testing)
int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.pop() << endl; // 30
    cout << st.pop() << endl; // 20
    cout << st.pop() << endl; // 10
    cout << st.pop() << endl; // -1 (stack empty)

    return 0;
}
