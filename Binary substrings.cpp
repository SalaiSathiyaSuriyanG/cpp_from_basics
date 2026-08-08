
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1;
        int prev = 0;
        int result = 0;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1])
                curr++;
            else{
                result += min(curr,prev);
                prev = curr;
                curr = 1;
            }    
        }
        result += min(curr,prev);
        
        return result;
    } 
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1;
        int prev = 0;
        int result = 0;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1])
                curr++;
            else{
                result += min(curr,prev);
                prev = curr;
                curr = 1;
            }    
        }
        result += min(curr,prev);
        
        return result;
    } 
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a binary string : ";
    cin >> s;

    cout <<"\nNumber of non-empty (contiguous) substrings"<< endl;
    cout <<"that have the same number of 0's and 1's : " << sol.countBinarySubstrings(s);

    return 0;
}