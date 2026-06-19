
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;

        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i])) count++;
        }
        
        /*We define the usage of capitals in a word to be right when one of the following cases holds:
        All letters in this word are capitals, like "USA".
        All letters in this word are not capitals, like "leetcode".
        Only the first letter in this word is capital, like "Google"./

        if(count == 0 || count == word.size()) return true;
        if(word.size() == 1) return true;
        if(count == 1 && isupper(word[0])) return true;
        else return false;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;

        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i])) count++;
        }

        /*We define the usage of capitals in a word to be right when one of the following cases holds:
        All letters in this word are capitals, like "USA".
        All letters in this word are not capitals, like "leetcode".
        Only the first letter in this word is capital, like "Google".*/


        if(count == 0 || count == word.size()) return true;
        if(word.size() == 1) return true;
        if(count == 1 && isupper(word[0])) return true;
        else return false;
    }
};

int main(){
    Solution sol;
    string word;
    cout <<"Enter a word : ";
    cin >> word;
    bool result = sol.detectCapitalUse(word);
    if(result)
        cout <<"True";
    else
        cout <<"False";

    return 0;    
}