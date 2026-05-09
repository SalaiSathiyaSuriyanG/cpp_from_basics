
/* ================================== LeetCode version ======================================

- Time Complexity: O(log_4(​n))
- Space Complexity: O(1)

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) 
            return false;
        while(n % 4 == 0){
            n /= 4; 
            /*A number is a power of 4 only if it can be divided by 4
            repeatedly until it becomes 1/
        }
        return n == 1;           
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) 
            return false;
        while(n % 4 == 0){
            n /= 4; 
            /*A number is a power of 4 only if it can be divided by 4
            repeatedly until it becomes 1*/
        }
        return n == 1;           
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter a number : ";
    cin >> n;

    if(sol.isPowerOfFour(n))
        cout << n <<" is a power of 4."<< endl;
    else
        cout << n <<" is not a power of 4."<< endl;

    return 0;    
}