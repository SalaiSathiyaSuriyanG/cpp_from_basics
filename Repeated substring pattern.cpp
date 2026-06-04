
/* ================================== LeetCode version ======================================

- Time Complexity: O(n^2) /*The outer loop runs upto n/2 times,and the inner loop can run upto n/len times,which in the worst case can be O(n). 
Therefore, the overall time complexity is O(n^2)/ 
- Space Complexity: O(n) //The string "repeated" can grow to size n.

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for(int len = 1; len <= n/2; len++){ //We start from 1 cause a string of length 0 doesn't make sense.

            if(n % len != 0) continue; /*if the pattern length doesn't divide the string length evenly,
            it's impossible for that pattern to repeat and fill the entire string/

            string pattern = s.substr(0,len); /*substr() takes a portion of the string. 
            syntax-->substr(starting index,no.of char(s) to take)/

            string repeated = "";

            for(int  i = 0; i < n / len; i++){
                repeated += pattern;
            }

            if(repeated == s)
                return true;
        }
        return false;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for(int len = 1; len <= n/2; len++){ //We start from 1 cause a string of length 0 doesn't make sense.

            if(n % len != 0) continue; /*if the pattern length doesn't divide the string length evenly,
            it's impossible for that pattern to repeat and fill the entire string*/

            string pattern = s.substr(0,len); /*substr() takes a portion of the string. 
            syntax-->substr(starting index,no.of char(s) to take)*/

            string repeated = "";

            for(int  i = 0; i < n / len; i++){
                repeated += pattern;
            }

            if(repeated == s)
                return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if(sol.repeatedSubstringPattern(s))
        cout <<"The string can be formed by repeating a substring.";

    else
        cout <<"The string cannot be formed by repeating a substring.";

    return 0;    
}