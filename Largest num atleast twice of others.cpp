
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = nums[0];
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > largest){
                largest = nums[i];
                index = i;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(i != index && largest < 2*nums[i])
                return -1;
        }
        return index;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = nums[0];
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > largest){
                largest = nums[i];
                index = i;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(i != index && largest < 2*nums[i])
                return -1;
        }
        return index;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"The index of the element that is atleast twice as all other elements is : " << sol.dominantIndex(nums) << endl;

    return 0;
}