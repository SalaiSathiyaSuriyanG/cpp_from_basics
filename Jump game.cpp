
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > farthest)
                return false;
            farthest = max(farthest, nums[i] + i);    
        }
        return true;
    }    
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > farthest)
                return false;
            farthest = max(farthest, nums[i] + i);    
        }
        return true;
    }    
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    cout <<"Can jump to the end of the array? : ";
    if(sol.canJump(nums))
        cout <<"Yes";
    else
        cout <<"No";  

    return 0;
}