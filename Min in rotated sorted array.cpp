
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n) 
- Space Complexity: O(1) 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] < nums[right])
                right = mid;

            if(nums[mid] > nums[right])
                left = mid + 1;    
        }
        return nums[left];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] < nums[right])
                right = mid;

            if(nums[mid] > nums[right])
                left = mid + 1;    
        }
        return nums[left];
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the number of elements in the rotated sorted array : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the rotated sorted array : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << "The minimum element in the rotated sorted array is : " << sol.findMin(nums);

    return 0;
}