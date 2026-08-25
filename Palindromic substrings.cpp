
/* ================================== LeetCode version ======================================

- Time Complexity: O(n^2) 
- Space Complexity: O(1) 

class Solution {
private:
    int expandFromCenter(string &s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            count += expandFromCenter(s, i, i);  //For odd length of string
            count += expandFromCenter(s, i, i + 1);  //For even length of string
        }
        return count; 
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    int expandFromCenter(string &s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            count += expandFromCenter(s, i, i);  //For odd length of string
            count += expandFromCenter(s, i, i + 1);  //For even length of string
        }
        return count; 
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    cin >> s;

    cout <<"Number of palindromic substrings : " << sol.countSubstrings(s);

    return 0;
}