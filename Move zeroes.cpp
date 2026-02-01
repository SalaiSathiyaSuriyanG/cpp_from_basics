#include <iostream>
#include <vector>
using namespace std;

/* ==================== Leetcode version ========================= 
    Leetcode Problem .no: 283

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZele = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[nonZele]=nums[i];
                nonZele++;
            }
        }
        while(nonZele < nums.size()){
            nums[nonZele] = 0;
            nonZele++;
        }
    }
}; 
==================================================== */

// ====================Runnable Version ===========================
void moveZeroes(vector<int>& nums){
    int nonZero = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            nums[nonZero] = nums[i];
            nonZero++;
        }
    }
    while(nonZero < nums.size()){
        nums[nonZero] = 0;
        nonZero++;
    }
}

int main() {
    int n;
    
	cout<<"Enter the Array size : ";  
	cin>> n;
	
    vector<int> nums(n);
    cout<<"Enter the Array elements : ";
    for(int i = 0; i < n; i++){
	cin>> nums[i];
    }
	
    moveZeroes(nums);
    
    cout<<"Array after moving Zeroes : ";
    for(int x : nums){
    cout<< x << " ";
	}
    return 0;
}
