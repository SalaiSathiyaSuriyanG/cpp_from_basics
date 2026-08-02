
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

// Continuous Subsequence = Subarray 
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int len = 1;
        int result = INT_MIN;

        for(int i = 0; i < n - 1; i++){
            if(nums[i] < nums[i + 1]){
                len++;
                result = max(result, len);
            }    
            else         
                len = 1;
        }
        result = max(result, len);

        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int len = 1;
        int result = INT_MIN;

        for(int i = 0; i < n - 1; i++){
            if(nums[i] < nums[i + 1]){
                len++;
                result = max(result, len);
            }    
            else         
                len = 1;
        }
        result = max(result, len);

        return result;
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
    cout <<"Length of the longest increasing subarray is : " << sol.findLengthOfLCIS(nums);
    
    return 0;
}