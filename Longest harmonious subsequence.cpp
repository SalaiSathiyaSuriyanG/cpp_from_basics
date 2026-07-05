
/* ================================== LeetCode version ======================================

- Time Complexity: O(n log n) 
- Space Complexity: O(1) 

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j = 0,maxLen = 0;

        for(int i = 0; i < nums.size(); i++){
            while(nums[i] - nums[j] > 1) j++;

            if(nums[i]- nums[j] == 1)
                maxLen = max(maxLen,i - j + 1);
        }
        return maxLen;
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
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j = 0,maxLen = 0;

        for(int i = 0; i < nums.size(); i++){
            while(nums[i] - nums[j] > 1) j++;

            if(nums[i]- nums[j] == 1)
                maxLen = max(maxLen,i - j + 1);
        }
        return maxLen;
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
    
    cout <<"The length of the longest harmonious subsequence is : " << sol.findLHS(nums);

    return 0;
}