
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_ele = *min_element(nums.begin(), nums.end());
        int max_ele = *max_element(nums.begin(), nums.end());

        int diff = (max_ele - k) - (min_ele + k);
        
        return (diff > 0) ? diff : 0;
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
    int smallestRangeI(vector<int>& nums, int k) {
        int min_ele = *min_element(nums.begin(), nums.end());
        int max_ele = *max_element(nums.begin(), nums.end());

        int diff = (max_ele - k) - (min_ele + k);
        
        return (diff > 0) ? diff : 0;
    }
};

int main(){
    Solution sol;
    int n, k;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"Enter the value of k : ";
    cin >> k;

    cout <<"The smallest range is : "<< sol.smallestRangeI(nums, k) << endl;

    return 0;
}