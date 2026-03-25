
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, char> mapping;
        unordered_set<char> used;
        
        for(int i = 0; i<s.size(); i++){
            char ch1 = s[i];
            char ch2 = t[i];
            if(mapping.count(ch1)){
                if(mapping[ch1] != ch2) // if ch1 is already mapped but != ch2
                    return false; 
            }
            else{
                if(used.count(ch2)) // if ch1 is not mapped but ch2 is already mapped
                    return false;
                mapping[ch1] = ch2;  // else map ch1 to ch2 and add ch2 to already used characters
                used.insert(ch2);    
            }
        }
        return true;    
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, char> mapping;
        unordered_set<char> used;
        
        for(int i = 0; i<s.size(); i++){
            char ch1 = s[i];
            char ch2 = t[i];
            if(mapping.count(ch1)){
                if(mapping[ch1] != ch2) // if ch1 is already mapped but != ch2
                    return false; 
            }
            else{
                if(used.count(ch2)) // if ch1 is not mapped but ch2 is already mapped
                    return false;
                mapping[ch1] = ch2;  // else map ch1 to ch2 and add ch2 to already used characters
                used.insert(ch2);    
            }
        }
        return true;    
    }
};

int main(){
    Solution sol;
    string s,t;
    cout <<"Enter the first string: ";
    cin >> s;
    cout <<"Enter the second string: ";
    cin >> t;
    cout <<"Are the two strings isomorphic? " ;
    cout <<"Yes(1) or No(0) : "<<sol.isIsomorphic(s,t);

    return 0;
}