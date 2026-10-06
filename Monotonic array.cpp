
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        
        bool inc = true;
        bool dec = true;

        for(int i = 1; i < n; i++){
            if(!inc && !dec) return false;

            if(nums[i] < nums[i - 1]) inc = false;

            if(nums[i] > nums[i - 1]) dec = false;
        }
        return inc || dec;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        
        bool inc = true;
        bool dec = true;

        for(int i = 1; i < n; i++){
            if(!inc && !dec) return false;

            if(nums[i] < nums[i - 1]) inc = false;

            if(nums[i] > nums[i - 1]) dec = false;
        }
        return inc || dec;
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

    cout <<"Is the array monotonic? : "<< (sol.isMonotonic(nums) ? "Yes" : "No")<< endl;

    return 0;
}