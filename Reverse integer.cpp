
/* ==================== LeetCode version =========================

- Time Complexity: O(log n)  //depends on number of digits in the input
- Space Complexity: O(1)

class Solution {
public:
    int reverse(int x) {
        int rem,rev = 0; 

        while(x != 0){
            rem = x % 10;
            x = x / 10;
            if(rev < INT_MIN/10 || rev > INT_MAX/10)
                return 0;
        rev = rev * 10 + rem;    
        }
        return rev;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rem,rev = 0; 

        while(x != 0){
            rem = x % 10;
            x = x / 10;
            if(rev < INT_MIN/10 || rev > INT_MAX/10)
                return 0;
        rev = rev * 10 + rem;    
        }
        return rev;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter an integer : ";
    cin >> n;
    cout << "Reversed integer : "<<sol.reverse(n);
    
    return 0;
}