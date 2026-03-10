
/* ==================== LeetCode version =========================

- Time Complexity: O(n)  // n is the length of the string 
- Space Complexity: O(1)

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long result = 0;
        int sign = 1;

        while(i < s.length() && s[i] == ' '){
            i++;
        }
        if(i < s.length() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-')
            sign = -1;
            i++;
        } 
        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            result = result * 10 + (s[i] - '0');
            i++;
            if(sign * result < INT_MIN)
                return INT_MIN;
            if(sign * result > INT_MAX)
                return INT_MAX;   
        }
        return sign * result;    
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long result = 0;
        int sign = 1;

        while(i < s.length() && s[i] == ' '){
            i++;
        }
        if(i < s.length() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-')
            sign = -1;
            i++;
        } 
        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            result = result * 10 + (s[i] - '0');
            i++;
            if(sign * result < INT_MIN)
                return INT_MIN;
            if(sign * result > INT_MAX)
                return INT_MAX;   
        }
        return sign * result;    
    }
};

int main(){
    Solution sol;
    string s;
    cout << "Enter a string : ";
    getline(cin,s);
    int result = sol.myAtoi(s);
    cout << "The integer value is : "<< result;
    
    return 0;
}