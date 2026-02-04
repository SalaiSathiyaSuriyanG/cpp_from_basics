
/* ==================== LeetCode version =========================
- Leetcode Problem :  
- Time Complexity: O(N*M)
- Space Complexity: O(M)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        return "";
        string prefix = strs[0];

        for(int i=1;i<strs.size();i++){
            while(strs[i].find(prefix)!=0){
            prefix.pop_back();
            if(prefix.empty())
            return "";
            }
        }
        return prefix;
    }
};

=============================================================== */

// ==================== Runnable Version =========================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        return "";
        string prefix = strs[0];

        for(int i=1;i<strs.size();i++){
            while(strs[i].find(prefix)!=0){
            prefix.pop_back();
            if(prefix.empty())
            return "";
            }
        }
    return prefix;
    }
};

int main() {
    Solution sol;
    int s;
    cout<<"Enter the number of string(s) : ";
    cin>>s;
    vector<string> strs(s);
    cout<<"Enter the strings : ";
    for(int i=0;i<s;i++){
    cin>>strs[i];
	}
	cout<<"Longest Common Prefix :"<<sol.longestCommonPrefix(strs);
    return 0;
}

