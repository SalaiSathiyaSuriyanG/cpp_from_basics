
/* ================================== LeetCode version ======================================

- Time Complexity: O(1) // Because it performs a constant number of operations regardless of the input size.
- Space Complexity: O(1)

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;

        return 1 + (num - 1) % 9;    
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return 0;

        return 1 + (num - 1) % 9;    
    }
};

int main(){
    Solution sol;
    int num;
    cout <<"Enter a positive integer : ";
    cin >> num;
    cout <<"The addition of digits is : " << sol.addDigits(num);

    return 0;
}