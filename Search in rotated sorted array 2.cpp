
/* ================================== LeetCode Version ======================================

- Time Complexity: O(log n) //Where n is the number of elements in the array. 
                            //In the worst case, it can reduce to O(n) when there are many duplicates.
- Space Complexity: O(1) 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) return true;

            // When duplicates found at boundaries,
            // we cannot determine which half of the array is sorted.
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
                continue;
            }

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else left = mid + 1;
            }

            else{
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }
                else right = mid - 1;
            }
        }
        return false;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target) return true;

            // When duplicates found at boundaries,
            // we cannot determine which half of the array is sorted.
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
                continue;
            }

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else left = mid + 1;
            }

            else{
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }
                else right = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    int n,target;
    
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"Enter the target element : ";
    cin >> target;

    bool result = sol.search(nums,target);
    cout <<"\nIs the target element found? : "<< (result ? "Yes" : "No")<< endl;

    return 0;
}