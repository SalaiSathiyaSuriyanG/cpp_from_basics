
/* ==================== LeetCode version =========================

- Time Complexity: O(n*k)
- Space Complexity: O(1)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i<nums.size(); i++){
            for(int j = i + 1; j <= i + k && j<nums.size(); j++)
                if(nums[i] == nums[j])
                return true;    
        }
        return false;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i<nums.size(); i++){
            for(int j = i + 1; j <= i + k && j<nums.size(); j++)
                if(nums[i] == nums[j])
                return true;    
        }
        return false;
    }
};

int main(){
    Solution sol;
	int n,k;
	cout<<"Enter the size of the Array: ";
	cin>>n;
	
	vector<int> nums(n);
	cout<<"Enter the Array elements: ";
	for(int i=0; i<n; i++){
	cin>>nums[i];
    }

    cout<<"Enter the value of k: ";
	cin>>k;

	cout<<"Does the array contain duplicates? (Yes = 1, No = 0) : "<<sol.containsNearbyDuplicate(nums, k);

    return 0;
}