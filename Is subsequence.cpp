
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
            }
            j++;    
        }
        return i == s.size();
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
            }
            j++;    
        }
        return i == s.size();
    }
};

int main(){
    Solution sol;
    string s,t;
    cout <<"Enter the string 1 : ";
    cin >> s;
    cout <<"Enter the string 2 : ";
    cin >> t;
    cout <<"Is string 1 a subsequence of string 2? : " << (sol.isSubsequence(s,t) ? "Yes" : "No");

    return 0;
}