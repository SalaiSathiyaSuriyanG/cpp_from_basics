
/* ==================== LeetCode version =========================
- Leetcode Problem :  
- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
            nums[i]=nums[j];
            i++;
            }
        }
        return i;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    Solution sol;
    int n;

    cout<<"Enter the array size : ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the array elements : ";
    for(int i=0;i<n;i++){
    cin>>nums[i];
	}

    int val;
    cout<<"Enter the value to remove : ";
    cin>>val;

    int k = sol.removeElement(nums, val);

    cout<<"Number of elements after removal : "<<k<<endl;
    cout<<"Remaining elements : ";
    for (int i = 0; i < k; i++) {
    cout<<nums[i]<<" ";
    }

    return 0;
}