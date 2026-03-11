
/* ==================== LeetCode version =========================

- Time Complexity: O(log n) // Because n keeps shrinking by a factor of 26 in each iteration
- Space Complexity: O(1)

class Solution {
public:
    string convertToTitle(int columnNumber) {
       string result = "";
       int n = columnNumber;
       while(n>0){
        n--;
        char c = 'A' + (n % 26);
        result += c;
        n = n/26;
       } 
       reverse(result.begin(),result.end());
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
    string convertToTitle(int columnNumber) {
       string result = "";
       int n = columnNumber;
       while(n>0){
        n--;
        char c = 'A' + (n % 26);
        result += c;
        n = n/26;
       } 
       reverse(result.begin(),result.end());
       return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the column number : ";
    cin >> n;
    cout << "The corresponding Excel sheet column title is : " << sol.convertToTitle(n);
    return 0;
}