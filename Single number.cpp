/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0;i<nums.size();i++){
            int num = nums[i];
            result ^= num;    
        }
        return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0;i<nums.size();i++){
            int num = nums[i];
            result ^= num;    
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the number of elements : ";
    cin >>n;
    vector<int> nums(n);
    cout <<"Enter the array elements : ";
    for(int i = 0;i<n;i++){
        cin >> nums[i];
    }
    int result = sol.singleNumber(nums);
    cout <<"The Single number is : "<<result;    
}