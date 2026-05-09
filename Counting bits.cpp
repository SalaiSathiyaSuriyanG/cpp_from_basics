
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)  
- Space Complexity: O(n) //for the output array

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1,0);

        for(int i = 1; i <= n; i++){
            ans[i] = ans[i >> 1] + (i & 1);
            // i >> 1 is equivalent to integer division by 2
            // Bitwise AND with 1 checks the last bit
        }
        return ans;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1,0);

        for(int i = 1; i <= n; i++){
            ans[i] = ans[i >> 1] + (i & 1);
            // i >> 1 is equivalent to integer division by 2
            // Bitwise AND with 1 checks the last bit
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter a non-negative integer : ";
    cin >> n;

    vector<int> result = sol.countBits(n);
    cout <<"Number of 1's in binary representation from 0 to "<< n <<" is : [  ";
    for(int i = 0; i <= n; i++){
        cout << result[i] <<"  ";
    }
    cout <<"]"<< endl;

    return 0;
}