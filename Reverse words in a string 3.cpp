
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) // 

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        
        stringstream ss(s); //Here,it allows us to read the string word-by-word
        string word,result = "";

        while(ss >> word){
            reverse(word.begin(),word.end());
            result += word + " ";
        }

        result.pop_back();
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return s;
        
        stringstream ss(s); //Here,it allows us to read the string word-by-word
        string word,result = "";

        while(ss >> word){
            reverse(word.begin(),word.end());
            result += word + " ";
        }

        result.pop_back();
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter the string : ";
    getline(cin,s);

    cout <<"Reversed string : "<< sol.reverseWords(s);

    return 0;
}