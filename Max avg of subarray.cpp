
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int maxSum = 0;
        
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        maxSum = sum;

        for(int i = k; i < nums.size(); i++){
            sum -= nums[i - k]; //Remove leftmost element
            sum += nums[i]; //Add new rightmost element
            
            if(sum > maxSum) maxSum = sum;
        }
        return (double)maxSum / k;
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
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int maxSum = 0;
        
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        maxSum = sum;

        for(int i = k; i < nums.size(); i++){
            sum -= nums[i - k]; //Remove leftmost element
            sum += nums[i]; //Add new rightmost element
            
            if(sum > maxSum) maxSum = sum;
        }
        return (double)maxSum / k;
    }
};

int main(){
    Solution sol;
    int n,k;

    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"Enter the window size : ";
    cin >> k;

    cout <<"The max average of the subarray of size "<< k <<" is : "<< sol.findMaxAverage(nums,k);

    return 0;
}