
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n)  
- Space Complexity: O(n) //We store the frequency of each element in a hash map. 

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > 1){
                return nums[i];
            }
        }
        return -1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > 1){
                return nums[i];
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout <<"The repeated element is : "<< sol.repeatedNTimes(nums) << endl;

    return 0;
}