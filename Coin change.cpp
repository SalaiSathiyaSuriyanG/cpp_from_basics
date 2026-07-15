
/* ================================== LeetCode version ======================================

- Time Complexity: O(A*n) //Where A is the target amount and n is the number of coin denominations (coins.size()).
- Space Complexity: O(A) 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //If the amount is 0, we don't need anymore coin
        if (amount == 0) return 0;

        //dp[i] stores the minimum number of coins needed to make amount i
        //Initialize all values to amount + 1 to represent that the amount is currently unreachable
        vector<int> dp(amount + 1, amount + 1);

        //Base case : amount 0 requires 0 coins
        dp[0] = 0;

        //Compute the answer for every amount from 1 to amount
        for (int i = 1; i <= amount; i++) { 
            for (int coin : coins) {

                //Only consider the current coin if it does not exceed the current amount
                if (i - coin >= 0)

                    // Update the minimum coins needed for amount i.
                    // 1 is for the current coin being used.
                    // dp[i - coin] is the best answer for the remaining amount.
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        //If dp[amount] was never updated from its initial value,the amount cannot be formed using the given coins
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //If the amount is 0, we don't need anymore coin
        if (amount == 0) return 0;

        //dp[i] stores the minimum number of coins needed to make amount i
        //Initialize all values to amount + 1 to represent that the amount is currently unreachable
        vector<int> dp(amount + 1, amount + 1);

        //Base case : amount 0 requires 0 coins
        dp[0] = 0;

        //Compute the answer for every amount from 1 to amount
        for (int i = 1; i <= amount; i++) { 
            for (int coin : coins) {

                //Only consider the current coin if it does not exceed the current amount
                if (i - coin >= 0)

                    // Update the minimum coins needed for amount i.
                    // 1 is for the current coin being used.
                    // dp[i - coin] is the best answer for the remaining amount.
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        //If dp[amount] was never updated from its initial value,the amount cannot be formed using the given coins
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(){
    Solution sol;
    int m,n;
    cout <<"Enter the no.of coin denominations : ";
    cin >> m;
    
    vector<int> coins(m);
    cout <<"Enter the coin denominations : ";
    for(int i = 0; i < m; i++){
        cin >> coins[i];
    }

    cout <<"Enter the target amount : ";
    cin >> n;

    cout <<"The minimum no.of coins needed is : "<< sol.coinChange(coins,n);

    return 0;
}