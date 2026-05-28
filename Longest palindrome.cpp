
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        int result = 0;

        for(char c : s){
            freq[c]++;
        }

        for(auto &[ch, count] : freq){   //Gives the largest even number <= count
            result += (count / 2)*2;
        }

        if(result < s.size()){  //Checks whether there was at least one odd character
            result++;
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        int result = 0;

        for(char c : s){
            freq[c]++;
        }

        for(auto &[ch, count] : freq){   //Gives the largest even number <= count
            result += (count / 2)*2;
        }

        if(result < s.size()){  //Checks whether there was at least one odd character
            result++;
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    cin >> s;
    cout <<"Length of the longest palindrome that can be built is : "<< sol.longestPalindrome(s);

    return 0;
}