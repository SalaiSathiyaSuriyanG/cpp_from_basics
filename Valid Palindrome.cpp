/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:    
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left]))
                left++;
            while (left < right && !isalnum(s[right]))
                right--;
            if (tolower(s[left]) != tolower(s[right])){
                return false; 
            }
            left++;
            right--;
        }
        return true; 
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
#include <cctype>   // for using isalnum() and tolower()
using namespace std;

class Solution {
public:    
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left]))
                left++;
            while (left < right && !isalnum(s[right]))
                right--;
            if (tolower(s[left]) != tolower(s[right])){
                return false;  
            }
            left++;
            right--;
        }
        return true; 
    }
};

int main() {
    Solution sol; 
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    bool result = sol.isPalindrome(input);
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}