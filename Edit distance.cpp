
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n)
- Space Complexity: O(m*n) 

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1,vector<int> (n + 1,0));  //Initially,initialize all rows and columns with 0

        for(int i = 0; i <= m; i++){ //Convert word1 to empty string
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++){ //Convert empty to word2
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){  //If the characters are same
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{ //If the characters are different, take min operation count
                    dp[i][j] = 1 + min({dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1]}); 
                }
            }
        }
        return dp[m][n];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1,vector<int> (n + 1,0));  //Initially,initialize all rows and columns with 0

        for(int i = 0; i <= m; i++){ //Convert word1 to empty string
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++){ //Convert empty to word2
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j - 1]){  //If the characters are same
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{ //If the characters are different, take min operation count
                    dp[i][j] = 1 + min({dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1]}); 
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution sol;
    string word1,word2;
    cout <<"Enter the first word : ";
    cin >> word1;
    cout <<"Enter the second word : ";
    cin >> word2;
    int result = sol.minDistance(word1,word2);
    cout <<"Minimum number of operations required to convert "<< word1 <<" to "<< word2 <<" is : "<< result;

    return 0;
}