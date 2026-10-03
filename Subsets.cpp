
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n*(2^n)) 
- Space Complexity: O(n) 

class Solution {
private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result){
        result.push_back(path);

        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        backtrack(nums, 0, path, result);
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result){
        result.push_back(path);

        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        backtrack(nums, 0, path, result);
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

    vector<vector<int>> result = sol.subsets(nums);

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