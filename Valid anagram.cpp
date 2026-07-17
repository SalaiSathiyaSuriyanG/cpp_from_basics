
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) //Here it's not O(n) cause the array size is fixed to 26 for lowercase letters.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int count : freq){
            if(count != 0)
                return false;
        }
        return true;
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
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int count : freq){
            if(count != 0)
                return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s,t;
    cout << "Enter the first string (in lowercase): ";
    cin >> s;
    cout << "Enter the second string (in lowercase): ";
    cin >> t;
    if(sol.isAnagram(s, t))
        cout <<"The strings are anagrams.";
    else
        cout <<"The strings are not anagrams.";

    return 0;    
}