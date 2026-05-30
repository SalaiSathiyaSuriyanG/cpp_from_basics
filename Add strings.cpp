
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(n) //We store every digit of the result.

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string result = "";
        int carry = 0;

        while(i >= 0 || j >= 0 || carry){
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            int sum = digit1 + digit2 + carry;

            result.push_back((sum % 10) + '0');
            carry = sum / 10;
            --i;
            --j;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string result = "";
        int carry = 0;

        while(i >= 0 || j >= 0 || carry){
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            int sum = digit1 + digit2 + carry;

            result.push_back((sum % 10) + '0');
            carry = sum / 10;
            --i;
            --j;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main(){
    Solution sol;
    string num1,num2;
    cout <<"Enter first number : ";
    cin >> num1;
    cout <<"Enter second number : ";
    cin >> num2;
    string result = sol.addStrings(num1, num2);
    cout <<"Sum : "<< result;

    return 0;
}