
/* ==================== LeetCode version =========================
- Leetcode Problem :  
- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        if(nums.empty())
        return 0;

        for(int j=1;j<nums.size();j++){
            if(nums[j] != nums[j-1]){
            nums[i] = nums[j];
            i++;}
        }
        return i;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.empty())
        return 0;
        int i=1;

        for(int j=1;j<nums.size();j++){
            if(nums[j] != nums[j-1]){
            nums[i] = nums[j];
            i++;}
        }
        return i;
    }
};

int main(){
	Solution sol;
	int n;
	cout<<"Enter the array size : ";
	cin>>n;
	vector<int> nums(n);
	cout<<"Enter the Sorted array elements : ";
	for(int i=0;i<n;i++){
	cin>>nums[i];
	}
	int k=sol.removeDuplicates(nums);
	cout<<"Number of Unique elements : "<<k;
	cout<<"\nUnique elements : ";
	for(int i=0;i<k;i++)
	cout<<nums[i];
	
	return 0;
}
