
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int curr = 0;
        for(int num : nums){
            if(num == 1){
                curr++;
                count = max(count,curr);
            }
            else
                curr = 0;
        }
        return count; 
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int curr = 0;
        for(int num : nums){
            if(num == 1){
                curr++;
                count = max(count,curr);
            }
            else
                curr = 0;
        }
        return count; 
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> nums(n);
    cout <<"Enter the elements of the array (0's and 1's) : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout <<"Maximum number of consecutive 1's is : " << sol.findMaxConsecutiveOnes(nums);

    return 0;
}