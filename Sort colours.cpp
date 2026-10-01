
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n^2) 
- Space Complexity: O(1) 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int min_indx = i;
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] < nums[min_indx]) min_indx = j;
            }
            swap(nums[i], nums[min_indx]);
        }
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int min_indx = i;
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] < nums[min_indx]) min_indx = j;
            }
            swap(nums[i], nums[min_indx]);
        }
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"\n0 - Red, 1 - White, 2 - Blue" << endl;
    cout <<"\nEnter the elements of the array (0, 1, or 2) :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sol.sortColors(nums);
    cout <<"Sorted array : ";
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }

    return 0;
}