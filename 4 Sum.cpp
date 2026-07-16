
/* ====================================== LeetCode version ===========================================

- Time Complexity: O(n^3) /* Sorting takes O(n log n) and 
                             the nested loops and two-pointer takes O(n^3) in the worst case./
- Space Complexity: O(1) // Since we use only a fixed number of variables. 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) // Skip nums[i] if it's the same as the nums[i-1].
            continue; 

            for(int j = i+1; j<nums.size(); j++){
                if(j > i+1 && nums[j] == nums[j-1]) // Skip nums[j] if it's the same as the nums[j-1].
                continue; 
                /* The above conditions are (i > 0) and (j > i+1) because if they are <= (0 or i+1)
                    nums[i-1] and nums[j-1] would be invalid. /

                int left = j + 1;
                int right = nums.size() - 1;

                while(left < right) {
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        result.push_back({nums[i],nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left-1])
                        left++;
                        while(left < right && nums[right] == nums[right+1]) 
                        right--;
                }
                else if(sum < target)
                    left++;
                else
                    right--;
                }
            }
        }
        return result;
    }
};
===================================================================================================== */

// ====================================== Runnable Version ============================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) // Skip nums[i] if it's the same as the nums[i-1].
            continue; 

            for(int j = i+1; j<nums.size(); j++){
                if(j > i+1 && nums[j] == nums[j-1]) // Skip nums[j] if it's the same as the nums[j-1].
                continue; 
                /* The above conditions are (i > 0) and (j > i+1) because if they are <= (0 or i+1)
                    nums[i-1] and nums[j-1] would be invalid. */

                int left = j + 1;
                int right = nums.size() - 1;

                while(left < right) {
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target) {
                        result.push_back({nums[i],nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left-1])
                        left++;
                        while(left < right && nums[right] == nums[right+1]) 
                        right--;
                }
                else if(sum < target)
                    left++;
                else
                    right--;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n, target;

    cout <<"Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array: ";
    for(int i = 0; i<nums.size(); i++){
        cin >> nums[i];
    }

    cout <<"Enter the target value: ";
    cin >> target;
    
    cout <<"Quadruplets that sum to " << target << " are: ";
    vector<vector<int>> result = sol.fourSum(nums,target);
    for(const auto& quad : result){
        cout <<" ["<< quad[0] <<","<< quad[1] <<","<< quad[2] <<","<< quad[3] <<"] ";
    }

    return 0;
}