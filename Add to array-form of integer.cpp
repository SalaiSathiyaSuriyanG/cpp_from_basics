
/* ================================== LeetCode Version ======================================

- Time Complexity: O(max(n, log k)) // Because the size of the output depends on both the length of the array and the number of digits in k
- Space Complexity: O(1) 

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int i = num.size() - 1;

        while(i >= 0 || k > 0){ 
            // If there are digits still left in the array num
            if(i >= 0){ 
                k += num[i]; // Add the current digit to k
                i--;  // Move to the next digit to the left
            } 
            
            // Take the last digit of the current sum and add it to our result
            result.push_back(k % 10); 
            
            // Remove the last digit from k
            k /= 10; 
        } 
        
        // Since we added the digits from right to left, the result is backwards. 
        // Reverse it to get the result in correct order.
        reverse(result.begin(), result.end());

        return result;
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
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int i = num.size() - 1;

        while(i >= 0 || k > 0){ 
            // If there are digits still left in the array num
            if(i >= 0){ 
                k += num[i]; // Add the current digit to k
                i--;  // Move to the next digit to the left
            } 
            
            // Take the last digit of the current sum and add it to our result
            result.push_back(k % 10); 
            
            // Remove the last digit from k
            k /= 10; 
        } 
        
        // Since we added the digits from right to left, the result is backwards. 
        // Reverse it to get the result in correct order.
        reverse(result.begin(), result.end());

        return result;
    }
};

int main(){
    Solution sol;
    int n, k;
    cout <<"Enter the number of digits in the array : ";
    cin >> n;

    vector<int> num(n);
    cout <<"Enter the digits :\n";
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    cout <<"Enter an integer : ";
    cin >> k;

    vector<int> result = sol.addToArrayForm(num, k);
    cout <<"\nThe sum is : [ ";
    for(int i : result){
        cout << i <<" ";
    }
    cout <<"]";

    return 0;
}