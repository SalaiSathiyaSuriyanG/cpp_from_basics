
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();

        while(i < n && j < n){
            // Increment i if nums[i] is already even
            if((nums[i] & 1) == 0) i += 2;

            // Increment j if nums[j] is already odd
            else if((nums[j] & 1) != 0) j += 2;

            // Swap if nums[i] is odd AND nums[j] is even
            else{
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();

        while(i < n && j < n){
            // Increment i if nums[i] is already even
            if((nums[i] & 1) == 0) i += 2;

            // Increment j if nums[j] is already odd
            else if((nums[j] & 1) != 0) j += 2;

            // Swap if nums[i] is odd AND nums[j] is even
            else{
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the size of the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array :" << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> result = sol.sortArrayByParityII(nums);
    cout <<"The sorted array is : ";
    for(int x : result){
        cout << x <<" ";
    }

    return 0;
}