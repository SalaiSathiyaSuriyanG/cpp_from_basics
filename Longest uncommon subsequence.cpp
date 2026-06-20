
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;

        return max(a.size(),b.size());

        /*1.Check for Identical Strings: 
        If the two strings are identical, there are no uncommon subsequences,so return -1. 
        
        2.Check for Different Lengths: 
        If lengths differ,the longer string cannot be a subsequence of the shorter one. 
        
        3.Check for Same Length but Different Strings: 
        If lengths are equal but strings differ,a length-N string cannot be a subsequence of another length-N string unless they are exactly the same./
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;

        return max(a.size(),b.size());

        /*1.Check for Identical Strings: 
        If the two strings are identical, there are no uncommon subsequences,so return -1. 
        
        2.Check for Different Lengths: 
        If lengths differ,the longer string cannot be a subsequence of the shorter one. 
        
        3.Check for Same Length but Different Strings: 
        If lengths are equal but strings differ,a length-N string cannot be a subsequence of another length-N string unless they are exactly the same.*/
    }
};

int main(){
    Solution sol;
    string a,b;
    cout<<"Enter first string : ";
    cin>>a;
    cout<<"Enter second string : ";
    cin>>b;

    cout<<"Length of longest uncommon subsequence is : "<<sol.findLUSlength(a,b);

    return 0;
}