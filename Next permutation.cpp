
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;   //We are comparing i with i+1. So,if i = n-1, then i+1 is out of bounds

        while (i >= 0 && nums[i] >= nums[i + 1]){   //We keep moving from right to left while the array is in descending order and find the breakpoint such that nums[i] < nums[i + 1]
            i--;
        }

        if (i >= 0){   //Find j where nums[j] is the next greater element of nums[i] from the right.Swap nums[i] and nums[j].Reverse everything after i
            int j = n - 1;
            while (nums[j] <= nums[i]){
                j--;
            }    
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }

        if (i >= 0){
            int j = n - 1;
            while (nums[j] <= nums[i]){
                j--;
            }    
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the array size : ";
    cin >> n;

    cout <<"Enter the array elements : ";
    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    cout <<"The permutated array is : ";
    sol.nextPermutation(nums);
    for(int i = 0; i<n; i++){
        cout << nums[i]<<" ";
    }
    cout << endl;
}