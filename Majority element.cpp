
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int candidate = 0,count = 0;
       for(int num : nums){
        if(count == 0){
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
       }    
       int freq = 0;           
       for(int num : nums)
        if(num == candidate) 
        freq++;
       
    return (freq > (nums.size()/2)) ? candidate : -1;
    }   
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int candidate = 0,count = 0;
       for(int num : nums){
        if(count == 0){
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
       }    
       int freq = 0;           
       for(int num : nums)
        if(num == candidate) 
        freq++;
       
    return (freq > (nums.size()/2)) ? candidate : -1;
    }   
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout <<"Enter the elements : ";
    for(int i = 0;i<n;i++){
        cin >> nums[i];
    }
    cout <<"Majority element is (-1 if none exists) : "<<sol.majorityElement(nums);

    return 0;
}