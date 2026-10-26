
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n log n) //We sort the array and then traverse it once for all elements.
- Space Complexity: O(1) 

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        // greater<T>() is a built-in functor.
        // It helps us to sort in decending order.

        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i + 1] + nums[i + 2] > nums[i])
                return nums[i] + nums[i + 1] + nums[i + 2];
        }
        return 0;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        // greater<T>() is a built-in functor.
        // It helps us to sort in decending order.

        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i + 1] + nums[i + 2] > nums[i])
                return nums[i] + nums[i + 1] + nums[i + 2];
        }
        return 0;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array :\n";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"The largest perimeter of a triangle that can be formed is : "<< sol.largestPerimeter(nums)<< endl;

    return 0;
}