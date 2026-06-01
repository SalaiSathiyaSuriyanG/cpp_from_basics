
/* ================================== LeetCode version ======================================

- Time Complexity: O(√n) // The while loop runs until the sum of the first k natural numbers exceeds n,
                            which happens around k ≈ √(2n).
- Space Complexity: O(1)

class Solution {
public:
    int arrangeCoins(int n) {
        int row = 1;
        while(n >= row){
            n -= row;
            row++;
        } 
        return row - 1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int row = 1;
        while(n >= row){
            n -= row;
            row++;
        } 
        return row - 1;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of coins: ";
    cin >> n;
    cout <<"Number of complete rows: " << sol.arrangeCoins(n);

    return 0;
}