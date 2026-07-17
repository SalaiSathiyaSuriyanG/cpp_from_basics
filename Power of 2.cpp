
/* ==================== LeetCode version =========================

- Time Complexity: O(1) // we are doing a constant number of operations.
- Space Complexity: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
        // if bitwise AND of n and n-1 is 0, then n is power of 2
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
        // if bitwise AND of n and n-1 is 0, then n is power of 2
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter an integer : ";
    cin >> n;
    if(sol.isPowerOfTwo(n))
        cout << n <<" is a power of 2";
    else
        cout << n <<" is not a poer of 2";
    
    return 0;
}