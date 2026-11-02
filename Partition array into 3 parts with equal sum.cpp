
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3 != 0) return false;
        int target = sum / 3;

        int count = 0, curr_sum = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            curr_sum += arr[i];
            if(curr_sum == target){
                count++;
                curr_sum = 0;

                // If we can find 2 valid parts before the end, the remaining 
                // elements are guaranteed to form a 3rd valid part.
                if(count == 2) return true;
            }
        }
        return false;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3 != 0) return false;
        int target = sum / 3;

        int count = 0, curr_sum = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            curr_sum += arr[i];
            if(curr_sum == target){
                count++;
                curr_sum = 0;

                // If we can find 2 valid parts before the end, the remaining 
                // elements are guaranteed to form a 3rd valid part.
                if(count == 2) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout <<"Enter the elements of the array :\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bool result = sol.canThreePartsEqualSum(arr);
    if(result)
        cout <<"\nThe array can be partitioned into three parts with equal sum."<< endl;
    else
        cout <<"\nThe array cannot be partitioned into three parts with equal sum."<< endl;

    return 0;
}