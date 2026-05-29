
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for(int num : nums){
            if(first == num || second == num || third == num) 
                continue;

            if(num > first){
                third = second;
                second = first;
                first = num;
            }
            else if(num > second){
                third = second;
                second = num; 
            }
            else if(num > third)
                third = num;
        }
        return (third == LONG_MIN) ? first : third;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for(int num : nums){
            if(first == num || second == num || third == num) 
                continue;

            if(num > first){
                third = second;
                second = first;
                first = num;
            }
            else if(num > second){
                third = second;
                second = num; 
            }
            else if(num > third)
                third = num;
        }
        return (third == LONG_MIN) ? first : third;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout <<"The third maximum element is: "<< sol.thirdMax(nums);
    
    return 0;
}