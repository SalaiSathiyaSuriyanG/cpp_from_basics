/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int currPrice : prices){
            if(currPrice < minPrice)
            minPrice = currPrice;
            else
            maxProfit = max(maxProfit,currPrice - minPrice);
        }
        return maxProfit;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int currPrice : prices){
            if(currPrice < minPrice)
            minPrice = currPrice;
            else
            maxProfit = max(maxProfit,currPrice - minPrice);
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    int n;
    
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}