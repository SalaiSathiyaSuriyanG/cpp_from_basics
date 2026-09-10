
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) //For storing the frequency of words

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> freq;
        unordered_set<string> b (banned.begin(), banned.end());
        string s, result;

        //ispunct() checks whether the character is a punctuation or not.
        for(auto& ch : paragraph){
            ch = ispunct(ch) ? ' ' : tolower(ch);
        }
        //stringstream works like cin, it breaks the string into separate words until a space appears.
        stringstream ss(paragraph);

        while(ss >> s){
            if(b.count(s) == 0 && ++freq[s] > freq[result]){
                result = s;
            }
        }
        return result; 
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <cctype>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> freq;
        unordered_set<string> b (banned.begin(), banned.end());
        string s, result;

        //ispunct() checks whether the character is a punctuation or not.
        for(auto& ch : paragraph){
            ch = ispunct(ch) ? ' ' : tolower(ch);
        }
        //stringstream works like cin, it breaks the string into separate words until a space appears.
        stringstream ss(paragraph);

        while(ss >> s){
            if(b.count(s) == 0 && ++freq[s] > freq[result]){
                result = s;
            }
        }
        return result; 
    }
};

int main(){
    Solution sol;
    vector<string> b;

    string p;
    cout <<"Enter the paragraph : ";
    getline(cin, p);

    string banned_w;
    cout <<"Enter the banned words (space-separated) : ";
    getline(cin, banned_w);
    
    
    stringstream ss(banned_w);
    string word;
    while(ss >> word){
        b.push_back(word);
    }

    cout <<"Most common word : " << sol.mostCommonWord(p, b) << endl;

    return 0;
}