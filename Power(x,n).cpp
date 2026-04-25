
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n) //BEcause, N/=2 cuts n in half at each step
- Space Complexity: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double result = 1.0;

        if(N == 0)
            return 1; 

        if(N < 0){ //x^(-n) = 1/(x^n)
            x = 1.0 / x; 
            N = -N; //n becomes positive
        }  

        while(N > 0){
            if(N % 2 == 1){ //If n is odd
                result *= x;
            }
            x *= x; //To move to next power(square the base)
            N /= 2; //Since I squared the base,I only need half the exponent now
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double result = 1.0;

        if(N == 0)
            return 1; 

        if(N < 0){ //x^(-n) = 1/(x^n)
            x = 1.0 / x; 
            N = -N; //n becomes positive
        }  

        while(N > 0){
            if(N % 2 == 1){ //If n is odd
                result *= x;
            }
            x *= x; //To move to next power(square the base)
            N /= 2; //Since I squared the base,I only need half the exponent now
        }
        return result;
    }
};

int main(){
    Solution sol;
    double x;
    cout <<"Enter the base value : ";
    cin >> x;

    int n;
    cout <<"Enter the exponent value : ";
    cin >> n;

    double result = sol.myPow(x,n);
    cout <<"The result of "<< x <<" raised to the power "<< n <<" is : "<< result;

    return 0;
}