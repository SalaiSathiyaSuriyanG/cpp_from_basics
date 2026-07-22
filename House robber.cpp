
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n);
        //dp[i] = maximum amount that can be robbed from houses 0 to i.

        dp[0] = nums[0];               //dp[i - 2]
        dp[1] = max(nums[0],nums[1]);  //dp[i - 1]

        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
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
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n);
        //dp[i] = maximum amount that can be robbed from houses 0 to i.

        dp[0] = nums[0];               //dp[i - 2]
        dp[1] = max(nums[0],nums[1]);  //dp[i - 1]

        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of houses : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the amount of money in each house : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"Maximum amount that can be robbed : " << sol.rob(nums);

    return 0;
}