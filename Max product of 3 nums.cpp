
/* ================================== LeetCode version ======================================

- Time Complexity: O(n log n) // due to sorting
- Space Complexity: O(log n) // due to sorting

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        long long Max1 =(long long)nums[n - 1]*nums[n - 2]*nums[n - 3];
        long long Max2 =(long long)nums[0]*nums[1]*nums[n - 1];

        return max(Max1,Max2);
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
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        long long Max1 =(long long)nums[n - 1]*nums[n - 2]*nums[n - 3];
        long long Max2 =(long long)nums[0]*nums[1]*nums[n - 1];

        return max(Max1,Max2);
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

    cout <<"The maximum product of three numbers in the array is : " << sol.maximumProduct(nums);

    return 0;
}