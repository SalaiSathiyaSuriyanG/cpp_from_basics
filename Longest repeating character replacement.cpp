
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int count = 0;
        int j = 0;
        vector<int> freq(26,0);

        for(int i = 0; i < n; i++){
            freq[s[i] - 'A']++;  

            count = max(count, freq[s[i] - 'A']); //Frequency of the most common character in the window.

            /* Shrink the window from the left until the current substring can be turned into 
            a string of one repeated character using at most k replacements. /
            while((i - j + 1) - count > k){
               freq[s[j] - 'A']--;  
               j++;
            }
            maxLen = max(maxLen, i - j + 1);
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
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int count = 0;
        int j = 0;
        vector<int> freq(26,0);

        for(int i = 0; i < n; i++){
            freq[s[i] - 'A']++;  

            count = max(count, freq[s[i] - 'A']); //Frequency of the most common character in the window.

            /* Shrink the window from the left until the current substring can be turned into 
            a string of one repeated character using at most k replacements. */
            while((i - j + 1) - count > k){
               freq[s[j] - 'A']--;  
               j++;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};

int main(){
    Solution sol;
    string s;
    int k;
    cout <<"Enter the string : ";
    cin >> s;

    cout <<"Enter the number of replacements allowed : ";
    cin >> k;

    int result = sol.characterReplacement(s, k);
    cout << "The length of the longest substring that can be obtained"
         <<" by replacing at most " << k << " characters is : "<< result << endl;

    return 0;
}