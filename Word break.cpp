
/* ================================== LeetCode version ======================================

- Time Complexity: O(n*m*l) //Where n is the length of the string s, m is the number of words in the wordDict, and l is the average length of the words in wordDict.
- Space Complexity: O(n) //Where n is the length of the string s.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++){
            for(const string& w : wordDict){
                int start = i - w.size();
                if(start >= 0 && dp[start] && s.substr(start,w.size()) == w){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++){
            for(const string& w : wordDict){
                int start = i - w.size();
                if(start >= 0 && dp[start] && s.substr(start,w.size()) == w){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    Solution sol;
    string s;
    int n;

    cout <<"Enter the string : ";
    cin >> s;

    cout <<"Enter the number of words in the dictionary : ";
    cin >> n;

    vector<string> wordDict(n);
    cout <<"Enter the words in the dictionary : ";
    for(int i = 0; i < n; i++){
        cin >> wordDict[i];
    }

    cout <<"Can the string be segmented? : " << (sol.wordBreak(s,wordDict) ? "Yes" : "No");

    return 0;
}