
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        
        int k = 2;
        
        //We can leave the first 2 elements as the problem 
        //allows each element to appear at most twice.
        //So it's considered valid even if they are duplicates.
        for(int i = 2; i < nums.size(); i++){
            //If the current element and the element we placed two steps 
            //behind in our newly built valid array are not the same,
            //it means we haven't reached a third duplicate yet.
            //So write the current element to our valid array.
            if(nums[i] != nums[k - 2]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        
        int k = 2;
        
        //We can leave the first 2 elements as the problem 
        //allows each element to appear at most twice.
        //So it's considered valid even if they are duplicates.
        for(int i = 2; i < nums.size(); i++){
            //If the current element and the element we placed two steps 
            //behind in our newly built valid array are not the same,
            //it means we haven't reached a third duplicate yet.
            //So write the current element to our valid array.
            if(nums[i] != nums[k - 2]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main(){
    Solution sol;
    int n;

    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array (sorted) :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int result = sol.removeDuplicates(nums);
    cout <<"The length of the array after removing duplicates is : " << result << endl;

    cout <<"The modified array is : ";
    for(int i = 0; i < result; i++){
        cout << nums[i] << " ";
    }

    return 0;
}