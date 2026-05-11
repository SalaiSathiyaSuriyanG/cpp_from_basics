
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};

int main(){
    Solution sol;
    string S;
    cout <<"Enter a string: ";
    getline(cin,S);

    cout <<"Reversed string : ";
    vector<char> s(S.begin(),S.end());

    sol.reverseString(s);
    for(char c : s){
        cout << c;
    }
    cout << endl;

    return 0;
}