
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);

        /*
        accumulate() reduces a range of elements down to a single value by combining them sequentially.
        Syntax : accumulate(beginning of seq, end of seq, initial value)
        /

        for(int i = 0; i < nums.size(); i++){
            rightSum -= nums[i];

            if(leftSum == rightSum) return i;

            else leftSum += nums[i]; 
        }
        return -1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);

        /*
        accumulate() reduces a range of elements down to a single value by combining them sequentially.
        Syntax : accumulate(beginning of seq, end of seq, initial value)
        */

        for(int i = 0; i < nums.size(); i++){
            rightSum -= nums[i];

            if(leftSum == rightSum) return i;

            else leftSum += nums[i]; 
        }
        return -1;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    if(sol.pivotIndex(nums) != -1)
        cout <<"The pivot index is : " << sol.pivotIndex(nums);
    else
        cout <<"There is no pivot index in the array";

    return 0;    
}