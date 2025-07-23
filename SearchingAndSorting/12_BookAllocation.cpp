// Problem: Book Allocation  
// Link: https://www.naukri.com/code360/problems/allocate-books_1090540  
// Difficulty: Medium  

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n log(sum))
// Space Complexity: O(1)

bool isValid(const vector<int>& arr, int n, int m, long long maxAllowedPages) {
    int students = 1;
    long long pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) return false;

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students > m ? false : true;
}

long long findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    long long sum = 0;
    int maxBook = 0;
    for (int pages : arr) {
        sum += pages;
        maxBook = max(maxBook, pages);
    }

    long long start = maxBook, end = sum, ans = -1;
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = arr.size();
    int m = 4;

    cout << "Minimum number of pages: " << findPages(arr, n, m) << endl;

    return 0;
}
