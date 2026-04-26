
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            curr_sum = max(nums[i],curr_sum + nums[i]);  // Decide whether to start a new subarray or continue with the previous one
            max_sum = max(curr_sum,max_sum);
        }
        return max_sum;
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
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            curr_sum = max(nums[i],curr_sum + nums[i]);  // Decide whether to start a new subarray or continue with the previous one
            max_sum = max(curr_sum,max_sum);
        }
        return max_sum;
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
    cout <<"The maximum subarray sum is : " << sol.maxSubArray(nums);

    return 0;
}