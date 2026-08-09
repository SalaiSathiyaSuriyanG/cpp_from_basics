
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) //Hashset is used to store the elements of the array.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int Max = 0;

        for (int num : st) {
            /*
            find() searches for a value in the unordered_set. If found, it returns an iterator pointing to that element. If not found, it returns st.end(). 
            /
            if (st.find(num - 1) == st.end()) {
                int currNum = num;
                int currLen = 1;

                while (st.find(currNum + 1) != st.end()) {
                    currNum++;
                    currLen++;
                }
                Max = max(Max, currLen);
            }
        }
        return Max;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int Max = 0;

        for (int num : st) {
            /*
            find() searches for a value in the unordered_set. If found, it returns an iterator pointing to that element. If not found, it returns st.end(). 
            */
            if (st.find(num - 1) == st.end()) {
                int currNum = num;
                int currLen = 1;

                while (st.find(currNum + 1) != st.end()) {
                    currNum++;
                    currLen++;
                }
                Max = max(Max, currLen);
            }
        }
        return Max;
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

    int result = sol.longestConsecutive(nums);
    cout << "The length of the longest consecutive sequence is : " << result;

    return 0;
}