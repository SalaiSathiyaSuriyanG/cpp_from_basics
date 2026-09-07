
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
        //string::npos is a special constant in C++ that means "Not Found" 
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
        //string::npos is a special constant in C++ that means "Not Found" 
    }
};

int main(){
    Solution sol;
    string s,g;
    cout <<"Enter the first string : ";
    cin >> s;
    cout <<"Enter the second string : ";
    cin >> g;

    if(sol.rotateString(s,g))
        cout <<"The second string is a rotation of the first string."<< endl;
    else
        cout <<"The second string is NOT a rotation of the first string."<< endl;

    return 0;    
}