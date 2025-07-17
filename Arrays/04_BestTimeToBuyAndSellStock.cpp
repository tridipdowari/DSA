// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty: Easy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}
