
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size() < 2) return nums;

        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & 1) == 0){
                swap(nums[left], nums[i]);
                left++;
            }
        }
        return nums;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size() < 2) return nums;

        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & 1) == 0){
                swap(nums[left], nums[i]);
                left++;
            }
        }
        return nums;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n); 
    cout <<"Enter the elements of the array :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"The sorted array by parity is : ";
    nums = sol.sortArrayByParity(nums);
    for(int i = 0; i < n; i++){
        cout << nums[i] <<" ";
    }
    cout << endl;

    return 0;
}