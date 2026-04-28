
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(n) //Worst case when all characters in pattern are unique and all words in s are unique

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while (ss >> word){
            words.push_back(word);
        }

        if (pattern.size() != words.size()) 
            return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++){
            char c = pattern[i];
            string w = words[i];

            if (charToWord.count(c)){
                if (charToWord[c] != w) return false;
            } 
            else
                charToWord[c] = w;

            if (wordToChar.count(w)){
                if (wordToChar[w] != c) return false;
            } 
            else
                wordToChar[w] = c;
        }
        return true;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        while (ss >> word){
            words.push_back(word);
        }

        if (pattern.size() != words.size()) 
            return false;

        unordered_map<char,string> charToWord;
        unordered_map<string,char> wordToChar;

        for (int i = 0; i < pattern.size(); i++){
            char c = pattern[i];
            string w = words[i];

            if (charToWord.count(c)){
                if (charToWord[c] != w) return false;
            } 
            else
                charToWord[c] = w;

            if (wordToChar.count(w)){
                if (wordToChar[w] != c) return false;
            } 
            else
                wordToChar[w] = c;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string pattern,s;

    cout <<"Enter the pattern: ";
    cin >> pattern;

    cin.ignore(); //clear newline
    cout <<"Enter the string: ";
    getline(cin, s);

    if (sol.wordPattern(pattern, s))
        cout <<"True"<< endl;
    else
        cout <<"False"<< endl;

    return 0;
}