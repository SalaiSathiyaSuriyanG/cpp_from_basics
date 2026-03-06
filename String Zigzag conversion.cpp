
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(n)

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size())
        return s;
        vector<string> rows(numRows);
        int current_row = 0;
        int direction = 1;
        for(char c : s){
            rows[current_row] += c;
            if(current_row == 0)
            direction = 1;
            if(current_row == numRows - 1)
            direction = -1;
            current_row += direction;
        }
        string result;
        for(string &r : rows)
        result += r;

        return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size())
        return s;
        vector<string> rows(numRows);
        int current_row = 0;
        int direction = 1;
        for(char c : s){
            rows[current_row] += c;
            if(current_row == 0)
            direction = 1;
            if(current_row == numRows - 1)
            direction = -1;
            current_row += direction;
        }
        string result;
        for(string &r : rows)
        result += r;

        return result;
    }
};

int main() {
    Solution sol;
    string s;
    int numRows;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of rows: ";
    cin >> numRows;

    string result = sol.convert(s, numRows);

    cout << "Output: " << result;

    return 0;
}