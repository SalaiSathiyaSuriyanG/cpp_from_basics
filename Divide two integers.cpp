
/* ==================== LeetCode version =========================

- Time Complexity: O(log n) // Because,the 2nd while loop doubles temp each time, 
                               which is log n. where n is the dividend. 
- Space Complexity: O(1)

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 0) return INT_MAX;    
        if(divisor == 1) return dividend;
        if(dividend == divisor) return 1;  

        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long div_d = llabs((long long)dividend);
        long long div_s = llabs((long long)divisor);
        int result = 0;    

        while(div_d >= div_s){
            long long temp = div_s;
            long long multiple = 1;
            while(div_d >= (temp << 1)){
                temp <<= 1;      //equivalent to * by 2
                multiple <<= 1;     //equivalent to * by 2
            }
            div_d -= temp;
            result += multiple;
        }
        if((dividend < 0) ^ (divisor < 0))
            result = -result;

        return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 0) return INT_MAX;    
        if(divisor == 1) return dividend;
        if(dividend == divisor) return 1;  

        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long div_d = llabs((long long)dividend);
        long long div_s = llabs((long long)divisor);
        int result = 0;    

        while(div_d >= div_s){
            long long temp = div_s;
            long long multiple = 1;
            while(div_d >= (temp << 1)){
                temp <<= 1;      //equivalent to * by 2
                multiple <<= 1;     //equivalent to * by 2
            }
            div_d -= temp;
            result += multiple;
        }
        if((dividend < 0) ^ (divisor < 0))
            result = -result;

        return result;
    }
};

int main(){
    Solution sol;
    int n,m;
    cout <<"Enter dividend and divisor: ";
    cin >> n >> m;
    cout <<"Quotient: " << sol.divide(n,m) << endl;

    return  0;
}