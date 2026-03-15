
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle){
            int current_letter_val = c - 'A' + 1;
            result = result * 26 + current_letter_val; 
        }
        return result;
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
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle){
            int current_letter_val = c - 'A' + 1;
            result = result * 26 + current_letter_val; 
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    cout << "Enter the column title : ";
    cin >> s;
    cout << "The corresponding Excel sheet column number is : " << sol.titleToNumber(s);

    return 0;
}