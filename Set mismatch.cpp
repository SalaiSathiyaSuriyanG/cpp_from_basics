
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = 0, miss = 0;

        vector<int> freq(n + 1,0);

        for(int i = 0; i < n; i++){ 
            /* For every number found at nums[i], the vector freq uses that number as an index, and increments the value stored at that index by 1 /
            freq[nums[i]]++;
        }

        for(int i = 1; i < freq.size(); i++){
            if(freq[i] == 2){
                dup = i;
            }
            if(freq[i] == 0){
                miss = i;
            }
        }
        return {dup,miss};
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = 0, miss = 0;

        vector<int> freq(n + 1,0);

        for(int i = 0; i < n; i++){ 
            /* For every number found at nums[i], the vector freq uses that number as an index, and increments the value stored at that index by 1 */
            freq[nums[i]]++;
        }

        for(int i = 1; i < freq.size(); i++){
            if(freq[i] == 2){
                dup = i;
            }
            if(freq[i] == 0){
                miss = i;
            }
        }
        return {dup,miss};
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements (n) : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements (1 to n): ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> result = sol.findErrorNums(nums);
    
    //Print the elements individually using indexing
    cout <<"Duplicate element : "<< result[0] << endl;
    cout <<"Missing element : "<< result[1] << endl;

    return 0;
}