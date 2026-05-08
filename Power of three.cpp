
/* ================================== LeetCode version ======================================

- Time Complexity: O(log_3(​n)) 
- Space Complexity: O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) 
            return false;
        while(n % 3 == 0){
            n /= 3; 
            /*A number is a power of 3 only if it can be divided by 3
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
    bool isPowerOfThree(int n) {
        if(n <= 0) 
            return false;
        while(n % 3 == 0){
            n /= 3; 
            /*A number is a power of 3 only if it can be divided by 3
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

    if(sol.isPowerOfThree(n))
        cout << n <<" is a power of 3."<< endl;
    else
        cout << n <<" is not a power of 3."<< endl;

    return 0;    
}