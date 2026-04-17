
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);  // update the farthest we can reach

        if (i == currentEnd) {  // if we reached the end of current, jump range
            jumps++;                  // we must take a jump
            currentEnd = farthest;    // update range
        }
    }
    return jumps;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);  // update the farthest we can reach

        if (i == currentEnd) {  // if we reached the end of current, jump range
            jumps++;                  // we must take a jump
            currentEnd = farthest;    // update range
        }
    }
    return jumps;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.jump(nums);
    cout <<"Minimum jumps: " << result;

    return 0;
}