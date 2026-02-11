
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
        return 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
            return i;
            if(nums[i]>target)
            return i;
        }
        return nums.size();
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
        return 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
            return i;
            if(nums[i]>target)
            return i;
        }
        return nums.size();
    }
};

int main(){
	Solution sol;
	int n,m;
	cout<<"Enter the Array size : ";
	cin>>n;
	vector<int>	nums(n);
	cout<<"Enter the Sorted array elements : ";
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	cout<<"Enter the target element : ";
	cin>>m;
	if(nums.empty()){
		cout<<"Empty array";
		return 0;
	}
	int index = sol.searchInsert(nums,m);
	cout<<"Element is found(or will be placed) at index "<<index;
	
	return 0;
}