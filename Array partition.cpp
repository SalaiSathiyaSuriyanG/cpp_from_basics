
/* ================================== LeetCode version ======================================

- Time Complexity: O(n log n) 
- Space Complexity: O(1) 

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2){
            sum += nums[i];
        }
        return sum;
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
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2){
            sum += nums[i];
        }
        return sum;
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
    cout << "From the pairs,maximum possible sum is : "<< sol.arrayPairSum(nums);

    return 0;
}