
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n)  

class Solution {
public:
    int help(vector<int>& nums,int start,int end){
        int n = nums.size();

        int prev_2 = nums[start];
        int prev_1 = max(nums[start],nums[start + 1]);

        int result = prev_1;

        for(int i = start + 2; i <= end; i++){
            result = max(prev_1,prev_2 + nums[i]);
            prev_2 = prev_1;
            prev_1 = result;
        }
        return result;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        return max(help(nums,0,n - 2),help(nums,1,n - 1));
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
    int help(vector<int>& nums,int start,int end){
        int n = nums.size();

        int prev_2 = nums[start];
        int prev_1 = max(nums[start],nums[start + 1]);

        int result = prev_1;

        for(int i = start + 2; i <= end; i++){
            result = max(prev_1,prev_2 + nums[i]);
            prev_2 = prev_1;
            prev_1 = result;
        }
        return result;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        return max(help(nums,0,n - 2),help(nums,1,n - 1));
    }    
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements : ";
    cin >> n;
    
    vector<int> nums(n);
    cout <<"Enter the elements : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"Maximum amount that can be robbed : "<< sol.rob(nums);

    return 0;
}