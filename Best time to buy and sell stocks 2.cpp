
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i + 1] > prices[i])
                profit += prices[i + 1] - prices[i];
        }
        return profit;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i + 1] > prices[i])
                profit += prices[i + 1] - prices[i];
        }
        return profit;
    }
};

int main(){
    Solution sol;
    int n, price;

    cout <<"Enter the number of days : ";
    cin >> n;

    vector<int> prices(n);
    cout <<"Enter the prices of the stock for "<< n <<" days :\n";
    for(int i = 0; i < n; i++){
        cin >> price;
        prices[i] = price;
    }

    cout <<"Maximum profit : "<< sol.maxProfit(prices) << endl;

    return 0;
}