
/* ================================== LeetCode version ======================================

- Time Complexity: O(n * n!)  
- Space Complexity: O(n * n!)
  //For both Time and Space, there are n! permutations, and each takes O(n) work

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start){
        if(start == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);            
            backtrack(nums, result, start + 1);     
            swap(nums[start], nums[i]);            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start){
        if(start == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);            
            backtrack(nums, result, start + 1);     
            swap(nums[start], nums[i]);            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements: ";
    cin >>n;

    vector<int> nums(n);
    cout <<"Enter the elements : ";
    for(int i = 0; i<nums.size(); i++){
        cin >> nums[i];
    }

    vector<vector<int>> permutations = sol.permute(nums);
    cout <<"Permutations are : ";
    for(const auto& permut : permutations){
        cout <<"[ ";
        for(int num : permut){
            cout <<num<<" ";
        }
        cout <<"]  ";
   }

   return 0;
}