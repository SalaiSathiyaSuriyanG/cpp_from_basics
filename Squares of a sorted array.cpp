
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;

        for(int i = right; i >= 0; i--){
            if(abs(nums[left]) > abs(nums[right])){
                result[i] = nums[left] * nums[left];
                left++;
            }
            else{
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;

        for(int i = right; i >= 0; i--){
            if(abs(nums[left]) > abs(nums[right])){
                result[i] = nums[left] * nums[left];
                left++;
            }
            else{
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array :\n";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> result = sol.sortedSquares(nums);
    cout <<"\nThe array of sorted squares is : [ ";
    for(int i = 0; i < n; i++){
        cout << result[i] <<" ";
    }
    cout <<"]\n";

    return 0;
}