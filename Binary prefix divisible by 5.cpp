
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int val = 0;
        vector<bool> result;

        for(int num : nums){
            val = ((val << 1) + num) % 5;   // << 1 is equivalent to multiplication by 2.
            result.push_back(val == 0);
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int val = 0;
        vector<bool> result;

        for(int num : nums){
            val = ((val << 1) + num) % 5;   // << 1 is equivalent to multiplication by 2.
            result.push_back(val == 0);
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of binary digits : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the binary digits (0 or 1) :\n";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<bool> result = sol.prefixesDivBy5(nums);
    cout <<"The resultant boolean vector is : ";
    for(auto val : result){
        cout << (val ? "True" : "False") <<" ";
    }
    cout << endl;

    return 0;
}