
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){    //b is conidered as the carry.Loop runs till the carry becomes 0.

            int carry = (a & b) << 1;
            //By left shifting the result of Bitwise AND of a and b by 1 position,we can find the carry.
            
            a = a^b;
            b = carry; 
        }
        return a;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){    //b is conidered as the carry.Loop runs till the carry becomes 0.

            int carry = (a & b) << 1;
            //By left shifting the result of Bitwise AND of a and b by 1 position,we can find the carry.
            
            a = a^b;
            b = carry; 
        }
        return a;
    }
};

int main(){
    Solution sol;
    int a,b;
    cout << "Enter two numbers to find their sum : ";
    cin >> a >> b;

    cout <<"The sum is : "<< sol.getSum(a,b); 
    
    return 0;
}