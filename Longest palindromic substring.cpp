
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) 
        return s;
        
        int start = 0;
        int maxLen = 1;
        
        for (int i = 0; i < s.size(); i++) {
            expandFromCenter(s, i, i, start, maxLen);
            expandFromCenter(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    } 
private:
    void expandFromCenter(string &s, int left, int right, int &start, int &maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
            left--;
            right++;
        }
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) 
        return s;
        
        int start = 0;
        int maxLen = 1;
        
        for (int i = 0; i < s.size(); i++) {
            expandFromCenter(s, i, i, start, maxLen);
            expandFromCenter(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    } 
private:
    void expandFromCenter(string &s, int left, int right, int &start, int &maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
            left--;
            right++;
        }
    }
};

int main() {
    Solution sol;
    string s;
    
    cout << "Enter a string: ";
    cin >> s;   
    
    string result = sol.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result;
    
    return 0;
}