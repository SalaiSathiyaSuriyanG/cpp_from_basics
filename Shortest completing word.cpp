
/* ================================== LeetCode version ======================================

- Time Complexity: O(L + n*m) //Where L = length of licensePlate, n = no.of words in words 
                              //and m = avg length of word. 
- Space Complexity: O(1) 

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> L_freq(26,0);
        string result = "";

        //Count the frequency of alphabetic characters in licensePlate (case-insensitive).
        for(char &ch : licensePlate){
            if(isalpha(ch)){
                ch = tolower(ch);
                L_freq[ch - 'a']++;
            }
        }

        for(string &word : words){
            vector<int> W_freq(26,0);

            //Count the frequency of characters in the current word.
            for(char &ch : word){
                W_freq[ch - 'a']++;
            }
            bool valid = true;

            //Check whether the current word contains the required characters of licensePlate 
            //with at least required frequency.
            for(int i = 0; i < 26; i++){
                if(W_freq[i] < L_freq[i]){
                    valid = false;
                    break;
                }
            }

            // Update the result if this is the first valid word found
            // or if the current valid word is shorter than the best valid word found so far.
            if(valid && (result.empty() || word.length() < result.length())){
                result = word;
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
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> L_freq(26,0);
        string result = "";

        //Count the frequency of alphabetic characters in licensePlate (case-insensitive).
        for(char &ch : licensePlate){
            if(isalpha(ch)){
                ch = tolower(ch);
                L_freq[ch - 'a']++;
            }
        }

        for(string &word : words){
            vector<int> W_freq(26,0);

            //Count the frequency of characters in the current word.
            for(char &ch : word){
                W_freq[ch - 'a']++;
            }
            bool valid = true;

            //Check whether the current word contains the required characters of licensePlate 
            //with at least required frequency.
            for(int i = 0; i < 26; i++){
                if(W_freq[i] < L_freq[i]){
                    valid = false;
                    break;
                }
            }

            // Update the result if this is the first valid word found
            // or if the current valid word is shorter than the best valid word found so far.
            if(valid && (result.empty() || word.length() < result.length())){
                result = word;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string licensePlate;
    int n;

    cout <<"Enter the License Plate : ";
    getline(cin, licensePlate);

    cout <<"Enter the number of words : ";
    cin >> n;

    vector<string> words(n);
    cout <<"\nEnter the words :" << endl;
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string result = sol.shortestCompletingWord(licensePlate, words);

    cout <<"\nShortest completing word : " << result << endl;

    return 0;
}