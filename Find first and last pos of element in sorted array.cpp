
/* ==================== LeetCode version =========================

- Time Complexity: O(log n) // Because we do this in Binary search.
- Space Complexity: O(1)

class Solution {
public:
    int findFirst(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                result = mid;
                right = mid - 1; //move right to before mid and keep searching left side
            }    
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }

    int findLast(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                result = mid;
                left = mid + 1; //move left to after mid and keep searching left side
            }    
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums,target), findLast(nums,target)};
    } 
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findFirst(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                result = mid;
                right = mid - 1; //move right to before mid and keep searching left side
            }    
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }

    int findLast(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                result = mid;
                left = mid + 1; //move left to after mid and keep searching left side
            }    
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums,target), findLast(nums,target)};
    } 
};

int main(){
    Solution sol;
    int n,target;
    cout <<"Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout <<"Enter the elements of the array: ";
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    cout <<"Enter the target value: ";
    cin >> target;
    vector<int> result = sol.searchRange(nums,target);
    cout <<"First and Last position of the target: [ "<< result[0]<<", "<< result[1]<<" ]";

    return 0;
}