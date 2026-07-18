
/* ================================== LeetCode version ======================================

- Time Complexity: O(n^2) 
- Space Complexity: O(n) 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        /* 
        max_element() → returns an iterator pointing to the largest element.
        '*' → dereferences the iterator to get the actual value.
        /
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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        /* 
        max_element() → returns an iterator pointing to the largest element.
        '*' → dereferences the iterator to get the actual value.
        */
    }    
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"The length of the longest increasing subsequence is : " << sol.lengthOfLIS(nums);

    return 0;
}