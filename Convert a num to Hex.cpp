
/* ================================== LeetCode version ======================================

- Time Complexity: O(8) //In the worst case,we will have at most 8 hexadecimal digits for a 32-bit integer.
- Space Complexity: O(1)

class Solution {
public:
    string toHex(int num) {
        if(num == 0)
        return "0";

        string digits = "0123456789abcdef";
        string result = "";
        unsigned int n = num; // Convert int to unsigned int to handle negative numbers

        while(n > 0){
            int rem = n % 16;
            result = digits[rem] + result; //We add in Front because remainder comes in reverse order
            n /= 16;
        } 
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0)
        return "0";

        string digits = "0123456789abcdef";
        string result = "";
        unsigned int n = num; // Convert int to unsigned int to handle negative numbers

        while(n > 0){
            int rem = n % 16;
            result = digits[rem] + result; //We add in Front because remainder comes in reverse order
            n /= 16;
        } 
        return result;
    }
};

int main(){
    Solution sol;
    int num;
    cout <<"Enter an integer: ";
    cin >> num;
    cout <<"Hexadecimal equivalent : "<< sol.toHex(num);

    return 0;
}