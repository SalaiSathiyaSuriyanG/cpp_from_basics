
/* ================================== LeetCode version ======================================

- Time Complexity: O(n*m) //where n is the length of text1 and m is the length of text2
- Space Complexity: O(n) 

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.size(),0);
        int maxLen = 0;

        for(char ch : text2){
            int currLen = 0;
            for(int i = 0; i < dp.size(); i++){
                //Update currLen to the maximum LCS length seen so far.
                if(currLen < dp[i])
                    currLen = dp[i];

                //If a common char is found at i, extend the maximum LCS length found before index i and update the max length. 
                else if(ch == text1[i]){
                    dp[i] = currLen + 1;
                    maxLen = max(maxLen,currLen + 1);
                }
            }
        }
        return maxLen;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.size(),0);
        int maxLen = 0;

        for(char ch : text2){
            int currLen = 0;
            for(int i = 0; i < dp.size(); i++){
                //Update currLen to the maximum LCS length seen so far.
                if(currLen < dp[i])
                    currLen = dp[i];

                //If a common char is found at i, extend the maximum LCS length found before index i and update the max length. 
                else if(ch == text1[i]){
                    dp[i] = currLen + 1;
                    maxLen = max(maxLen,currLen + 1);
                }
            }
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    string t1,t2;

    cout <<"Enter string 1 : ";
    cin >> t1;
    cout <<"Enter string 2 : ";
    cin >> t2;

    cout <<"Length of Longest Common Subsequence : " << sol.longestCommonSubsequence(t1,t2);

    return 0;
}
