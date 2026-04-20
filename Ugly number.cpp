
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n) //We divide n by 2,3 and 5 as many times as possible.
- Space Complexity: O(1)

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;

        for(int i : {2,3,5}){
            while(n % i == 0)
                n /= i;
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
    bool isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;

        for(int i : {2,3,5}){
            while(n % i == 0)
                n /= i;
        }

        return n == 1;    
    }
};

int main(){
    Solution sol;
    int n;

    cout <<"Enter an integer : ";
    cin >> n;

    if(sol.isUgly(n))
        cout <<"it is an ugly number.";
    else
        cout <<"It is not an ugly number.";

    return 0;
}