
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n)  

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1,0);

        if(s[0] == '0') return 0;

        dp[0] = 1;  //Base case: one way to decode an empty string.
        dp[1] = (s[0] != '0') ? 1 : 0;  //One way, if the first digit is valid (1-9),otherwise 0.

        for(int i = 2; i <= n; i++){
            int one = s[i - 1] - '0';    //Decode the last digit alone.
            int two = stoi(s.substr(i - 2,2));    //Decode the last two digits together.

            if(1 <= one && one <= 9)
                dp[i] += dp[i - 1];
            
            if(10 <= two && two <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
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
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1,0);

        if(s[0] == '0') return 0;

        dp[0] = 1;  //Base case: one way to decode an empty string.
        dp[1] = (s[0] != '0') ? 1 : 0;  //One way, if the first digit is valid (1-9),otherwise 0.

        for(int i = 2; i <= n; i++){
            int one = s[i - 1] - '0';    //Decode the last digit alone.
            int two = stoi(s.substr(i - 2,2));    //Decode the last two digits together.

            if(1 <= one && one <= 9)
                dp[i] += dp[i - 1];
            
            if(10 <= two && two <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    string s;

    cout <<"Enter the integer string to decode : ";
    cin >> s;

    cout <<"Number of possible decodings : " << sol.numDecodings(s);

    return 0;
}