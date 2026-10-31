
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n * m) //Where n is the number of words and m is the avg length of each word.
- Space Complexity: O(1) 

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> minFreq(26, INT_MAX);
        
        for(const string& word : words){
            vector<int> freq(26, 0);
            for(char ch : word){
                freq[ch - 'a']++;
            }
            
            for(int i = 0; i < 26; i++){
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }
        
        for(int i = 0; i < 26; i++){
            while(minFreq[i] > 0){
                result.push_back(string(1, i + 'a'));
                minFreq[i]--;
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
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> minFreq(26, INT_MAX);
        
        for(const string& word : words){
            vector<int> freq(26, 0);
            for(char ch : word){
                freq[ch - 'a']++;
            }
            
            for(int i = 0; i < 26; i++){
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }
        
        for(int i = 0; i < 26; i++){
            while(minFreq[i] > 0){
                result.push_back(string(1, i + 'a'));
                minFreq[i]--;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of words : ";
    cin >> n;

    vector<string> words(n);
    cout <<"Enter the words :\n";
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }

    vector<string> result = sol.commonChars(words);
    cout <<"The common characters are : [ ";
    for (const string& ch : result) {
        cout << ch <<" ";
    }
    cout <<"]"<< endl;

    return 0;
}