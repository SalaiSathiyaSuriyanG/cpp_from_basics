
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = 0;
        long long expected_sum = n*(n + 1) / 2;

        for(int i = 0; i < n; i++){
        actual_sum += nums[i];  
        }
        int missing_num = expected_sum - actual_sum;

        return missing_num;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = 0;
        long long expected_sum = n*(n + 1) / 2;

        for(int i = 0; i < n; i++){
        actual_sum += nums[i];  
        }
        int missing_num = expected_sum - actual_sum;

        return missing_num;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the array size : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the array elements : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout <<"The missing number is : "<<sol.missingNumber(nums);

    return 0;
}