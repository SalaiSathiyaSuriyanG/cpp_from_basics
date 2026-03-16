
/* ==================== LeetCode version =========================

- Time Complexity: O(n^2) // Sorting takes O(n log n) and the two-pointer approach takes O(n^2) in the worst case.
- Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) 
            continue; 
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1])
                    left++;
                    while(left < right && nums[right] == nums[right+1]) 
                    right--;
                }
                else if(sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return result;
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) 
            continue; 
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1])
                    left++;
                    while(left < right && nums[right] == nums[right+1]) 
                    right--;
                }
                else if(sum < 0)
                    left++;
                else
                    right--;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout <<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<vector<int>> result = sol.threeSum(nums);
    cout <<"The triplets that sum to zero are: "<<endl;

    for(const auto& triplet : result){
        cout <<"["<< triplet[0] <<","<< triplet[1] <<","<< triplet[2] <<"]"<<endl;
    }

    return 0;
}