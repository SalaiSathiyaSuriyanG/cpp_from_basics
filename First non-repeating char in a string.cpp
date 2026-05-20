
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);

        for(char ch : s){  //Count the no.of occurence of each character
            freq[ch - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            if(freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
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
    int firstUniqChar(string s) {
        vector<int> freq(26,0);

        for(char ch : s){  //Count the no.of occurence of each character
            freq[ch - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            if(freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    cin >> s;
    cout <<"The index of the first non-repeating character is : "<< sol.firstUniqChar(s);

    return 0;
}