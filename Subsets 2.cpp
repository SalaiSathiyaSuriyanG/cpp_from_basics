
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n * 2^n) //Because for each element,
                              //we have two choices: either to include it in the subset or not. 
- Space Complexity: O(n * 2^n) //Because we are storing all the subsets in the result vector.

class Solution {
private:
    void helper(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result){

        result.push_back(path);

        for(int i = start; i < nums.size(); i++){
            // Skip the duplicate elements
            if(i > start && nums[i] == nums[i - 1]) continue;
            
            path.push_back(nums[i]);
            helper(nums, i + 1, path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        
        sort(nums.begin(), nums.end());
        helper(nums, 0, path, result);
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void helper(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result){

        result.push_back(path);

        for(int i = start; i < nums.size(); i++){
            // Skip the duplicate elements
            if(i > start && nums[i] == nums[i - 1]) continue;
            
            path.push_back(nums[i]);
            helper(nums, i + 1, path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        
        sort(nums.begin(), nums.end());
        helper(nums, 0, path, result);
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the set : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the set :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout <<"\nThe subsets are :\n[\n";
    for(const auto& subset : result) {
        cout <<"  [ ";
        for(int num : subset) {
            cout << num <<" ";
        }
        cout <<"]\n";
    }
    cout <<"]"<< endl;

    return 0;
}