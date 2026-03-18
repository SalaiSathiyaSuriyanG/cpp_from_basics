
/* ==================== LeetCode version =========================

- Time Complexity: O(n^2) // O(n log n) for sorting and O(n^2) for the two-pointer approach
- Space Complexity: O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i<nums.size(); i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(abs(sum - target) < abs(closest - target))
                closest = sum; 
            
            if(sum < target)
            left++;
            else
            right--;
            }
        }
        return closest; 
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i<nums.size(); i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(abs(sum - target) < abs(closest - target))
                closest = sum; 
            
            if(sum < target)
            left++;
            else
            right--;
            }
        }
        return closest; 
    }
};

int main(){
    Solution sol;
    vector<int> nums;
    int target,n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }
    cout << "Enter the target value: ";
    cin >> target;
    
    int result = sol.threeSumClosest(nums, target);
    cout << "The closest sum is : "<<result;

    return 0;
}