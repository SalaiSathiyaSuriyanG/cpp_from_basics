
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for(int i = 0; i<nums.size(); i++){
            int start_val = nums[i];

            while(i+1 < nums.size() && nums[i+1] == nums[i] + 1){
                i++;
            }    
            int end_val = nums[i];

            if(start_val == end_val)
                result.push_back(to_string(start_val));
            else
                result.push_back(to_string(start_val) + "->" + to_string(end_val));
        }
        return result;
    }    
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for(int i = 0; i<nums.size(); i++){
            int start_val = nums[i];

            while(i+1 < nums.size() && nums[i+1] == nums[i] + 1){
                i++;
            }    
            int end_val = nums[i];

            if(start_val == end_val)
                result.push_back(to_string(start_val));
            else
                result.push_back(to_string(start_val) + "->" + to_string(end_val));
        }
        return result;
    }    
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array: ";
    cin >>n;
    vector<int> nums(n);
    cout <<"Enter the elements of the array: ";
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    vector<string> result = sol.summaryRanges(nums);
    cout <<"Summary Ranges: ";
    for(const string& range : result){
        cout << range <<"  ";
    }
    cout << endl;

    return 0;
}