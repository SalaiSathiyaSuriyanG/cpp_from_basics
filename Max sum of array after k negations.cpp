
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n log n) 
- Space Complexity: O(1) 

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && k > 0; i++) {
            if(nums[i] < 0){
                nums[i] = -nums[i];
                k--;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(k % 2 != 0){
            int min_num = *min_element(nums.begin(), nums.end());
            sum -= 2 * min_num;
        }
        return sum;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && k > 0; i++) {
            if(nums[i] < 0){
                nums[i] = -nums[i];
                k--;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(k % 2 != 0){
            int min_num = *min_element(nums.begin(), nums.end());
            sum -= 2 * min_num;
        }
        return sum;
    }
};

int main(){
    Solution sol;
    int n,k;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array :\n";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"Enter the value of k : ";
    cin >> k;

    int result = sol.largestSumAfterKNegations(nums, k);
    cout <<"The largest sum after " << k << " negations is : " << result << endl;

    return 0;
}