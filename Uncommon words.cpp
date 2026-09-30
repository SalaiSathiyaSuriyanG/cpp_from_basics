
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n + m) 
- Space Complexity: O(n + m) 

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Combine both sentences with spaces
        string s = s1 + " " + s2 + " ";
        stringstream str(s);
        
        // Store the frequency of all words
        unordered_map<string, int> freq;
        string temp;
        while(str >> temp){
            freq[temp]++;
        }
        
        // Collect words that appear exactly once
        vector<string> result;
        for(auto& val : freq){
            if(val.second == 1){
                result.push_back(val.first);
            }
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Combine both sentences with spaces
        string s = s1 + " " + s2 + " ";
        stringstream str(s);
        
        // Store the frequency of all words
        unordered_map<string, int> freq;
        string temp;
        while(str >> temp){
            freq[temp]++;
        }
        
        // Collect words that appear exactly once
        vector<string> result;
        for(auto& val : freq){
            if(val.second == 1){
                result.push_back(val.first);
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s1, s2;
    cout <<"Enter two strings : ";
    getline(cin, s1);
    getline(cin, s2);

    vector<string> result = sol.uncommonFromSentences(s1, s2);
    cout <<"Uncommon words are : ";
    for(const string& word : result){
        cout << word <<"  ";
    }
    cout << endl;

    return 0;
}