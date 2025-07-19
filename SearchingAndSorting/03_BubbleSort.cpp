// Problem: Bubble Sort
// Link: https://www.naukri.com/code360/problems/bubble-sort_624380
// Difficulty: Easy

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n^2) in worst-case, O(n) in best-case (when already sorted)
// Space Complexity: O(1)

void bubbleSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool isSwap = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        // If the array is already sorted
        if (!isSwap) break;
    }
}

int main() {
    vector<int> arr = {41, 467, 334, 500, 169, 724, 478, 358, 962, 464};
    int n = arr.size();

    bubbleSort(arr, n);

    cout << "Sorted array using Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
