
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(k) 
/*Space depends on the number of unique elements (k) present in the nums array, where k ≤ n.
In the worst case, we may have to store all the elements in the hash maps. */

/*
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first_pos;   
        int degree = 0;
        int Min = 0;

        for (int i = 0; i < nums.size(); i++) {
            if(first_pos.count(nums[i]) == 0)
                first_pos[nums[i]] = i;

            if(++count[nums[i]] > degree){
                degree = count[nums[i]];
                Min = i - first_pos[nums[i]] + 1;
            } 

            else if(count[nums[i]] == degree)
                Min = min(Min, i - first_pos[nums[i]] + 1);
        }
        return Min;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*Task is to find the smallest possible length of a (contiguous) subarray of nums, 
that has the same degree as nums*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first_pos;   
        int degree = 0;
        int Min = 0;

        for (int i = 0; i < nums.size(); i++) {
            if(first_pos.count(nums[i]) == 0)
                first_pos[nums[i]] = i;

            if(++count[nums[i]] > degree){
                degree = count[nums[i]];
                Min = i - first_pos[nums[i]] + 1;
            } 

            else if(count[nums[i]] == degree)
                Min = min(Min, i - first_pos[nums[i]] + 1);
        }
        return Min;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"The shortest subarray with the same degree is : " << sol.findShortestSubArray(nums);
    
    return 0;
}