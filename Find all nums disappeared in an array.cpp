
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != nums[nums[i] - 1])
                swap(nums[i],nums[nums[i] - 1]);
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1)
                result.push_back(i+1);
        }
        return result;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != nums[nums[i] - 1])
                swap(nums[i],nums[nums[i] - 1]);
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1)
                result.push_back(i+1);
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the no.of integers : ";
    cin >> n;
    
    vector<int> nums(n);
    cout <<"Enter the integers : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"The disappeared numbers are : ";
    vector<int> result = sol.findDisappearedNumbers(nums);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] <<" ";
    }

    return 0;
}