
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() - 1;
        int product = 1;
        int max_prod = INT_MIN;

        for(int i : nums){
            product *= i;
            max_prod = max(max_prod,product);

            //We restart the product from 1 because,once the product becomes 0,it stays 0 forever making us unable to find the max after that.
            if(i == 0) product = 1;
        }

        product = 1;
        for(int i = n; i >= 0; i--){
            product *= nums[i];
            max_prod = max(max_prod,product);

            if(nums[i] == 0) product = 1;
        }
        return max_prod;
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
    int maxProduct(vector<int>& nums) {
        int n = nums.size() - 1;
        int product = 1;
        int max_prod = INT_MIN;

        for(int i : nums){
            product *= i;
            max_prod = max(max_prod,product);

            //We restart the product from 1 because,once the product becomes 0,it stays 0 forever making us unable to find the max after that.
            if(i == 0) product = 1;
        }

        product = 1;
        for(int i = n; i >= 0; i--){
            product *= nums[i];
            max_prod = max(max_prod,product);

            if(nums[i] == 0) product = 1;
        }
        return max_prod;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    cout << "The maximum product of subarray is : " << sol.maxProduct(nums);

    return 0;
}