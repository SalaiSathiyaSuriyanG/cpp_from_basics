
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        answer[0] = 1;

        //First,calculate the left product of each element.
        for(int i = 1; i < n; i++){
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        //Then,calculate the right product of each element and multiply it with the left product.
        int right = 1;
        for(int i = n - 1; i >= 0; i--){
            answer[i] *= right;
            right *= nums[i];
        }
        return answer;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        answer[0] = 1;

        //First,calculate the left product of each element.
        for(int i = 1; i < n; i++){
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        //Then,calculate the right product of each element and multiply it with the left product.
        int right = 1;
        for(int i = n - 1; i >= 0; i--){
            answer[i] *= right;
            right *= nums[i];
        }
        return answer;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> result = sol.productExceptSelf(nums);
    cout << "The product of array except self is : ";
    for(int i = 0; i < n; i++){
        cout << result[i] <<" ";
    }
    cout << endl;

    return 0;
}