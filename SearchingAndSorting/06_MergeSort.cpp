// Problem: Merge Sort
// Link: https://www.naukri.com/code360/problems/merge-sort_5846
// Difficulty: Medium

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }

    while (right <= high) {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSortHelper(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSortHelper(arr, low, mid);
    mergeSortHelper(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

vector<int> mergeSort(vector<int>& arr, int n) {
    mergeSortHelper(arr, 0, n - 1);
    return arr;
}

int main() {
    vector<int> arr = {5, 2, 8, 4, 1};
    int n = arr.size();

    vector<int> sortedArr = mergeSort(arr, n);

    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
