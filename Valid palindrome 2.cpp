
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            if(s[left] != s[right]){
                //Try skipping either the left character or the right character results in Palindrome
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalindrome(const string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;

            left++;
            right--;
        }
        return true;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            if(s[left] != s[right]){
                //Try skipping either the left character or the right character results in Palindrome
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalindrome(const string &s, int left, int right){
        while(left < right){
            if(s[left] != s[right]) return false;

            left++;
            right--;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    cin >> s;

    cout <<"Could this become a valid palindrome if we delete at most one character? : " << (sol.validPalindrome(s) ? "Yes" : "No") << endl;

    return 0;
}