
/* ==================== LeetCode version =========================
- Leetcode Problem : 9 
- Time Complexity: O(n)
- Space Complexity: O(n)

class Solution {
public:
    bool isPalindrome(int x) {
        string n = to_string(x);
        string rev = n;
        reverse(rev.begin(),rev.end());
        if(x<0)
        return false;
        else if(n == rev)
        return true;
        else 
        return false;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string n = to_string(x);
        string rev = n;
        reverse(rev.begin(), rev.end());
        if (x < 0)
        return false;
        else if (n == rev)
        return true;
        else
        return false;
    }
};

int main() {
    Solution sol;
    int num;
    cout<< "Enter a number: ";
    cin>> num;

    if (sol.isPalindrome(num))
    cout<<num<< " is a Palindrome."<<endl;
    else
    cout<<num<< " is not a Palindrome."<<endl;
    return 0;
}