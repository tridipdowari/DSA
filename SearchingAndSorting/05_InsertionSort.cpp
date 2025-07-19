// Problem: Insertion Sort
// Link: https://www.naukri.com/code360/problems/insertion-sort_624381
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)

void insertionSort(int n, vector<int> &arr) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};
    int n = arr.size();

    insertionSort(n, arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
