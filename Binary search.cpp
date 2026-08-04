
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n) 
- Space Complexity: O(1) 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) return mid; 

            else if(nums[mid] < target) left = mid + 1;

            else right = mid - 1;
        }
        return -1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) return mid; 

            else if(nums[mid] < target) left = mid + 1;

            else right = mid - 1;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    int n, target;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"Enter the target element to search : ";
    cin >> target;
    
    int result = sol.search(nums, target);
    if(result == -1)
        cout <<"Element not found in the array.";
    else
        cout <<"Element found at index : " << result;

    return 0;    
}