
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int fib(int n) {
       if(n <= 1) return n;

       return fib(n - 1) + fib(n - 2); 
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
       if(n <= 1) return n;

       return fib(n - 1) + fib(n - 2); 
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter an integer : ";
    cin >> n;
    cout <<"The fibonacci of "<< n <<" is : "<< sol.fib(n);

    return 0;
}