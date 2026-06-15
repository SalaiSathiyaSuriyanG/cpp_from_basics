
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n)  //where k is the number of digits in num, O(k) = O(log_7(n)) = O(log n)
- Space Complexity: O(log n) 

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";

        bool negative = num < 0;
        num = abs(num);
        string result = "";

        while(num > 0){
            result += num % 7 + '0';
            num /= 7;
        }
        reverse(result.begin(),result.end());
        if(negative) result = "-" + result;

        return result;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";

        bool negative = num < 0;
        num = abs(num);
        string result = "";

        while(num > 0){
            result += num % 7 + '0';
            num /= 7;
        }
        reverse(result.begin(),result.end());
        if(negative) result = "-" + result;

        return result;
    }
};

int main(){
    Solution sol;
    int num;
    cout <<"Enter an integer : ";
    cin >> num;
    cout <<"Base 7 equivalent of "<< num <<" is : "<< sol.convertToBase7(num);
    
    return 0;
}