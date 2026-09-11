
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = { ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.", "....", "..", ".---", "-.-",  ".-..", "--", "-.", "---",  ".--.", "--.-", ".-.",  "...",  "-", "..-", "...-", ".--",  "-..-", "-.--", "--.." };

        unordered_set<string> s;
        int n = words.size(); 

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < words[i].size(); j++) {
                string ch = morse[words[i][j] - 'a'];
                temp += ch;
            }
            s.insert(temp);
        }
        return s.size();
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream> 
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = { ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.", "....", "..", ".---", "-.-",  ".-..", "--", "-.", "---",  ".--.", "--.-", ".-.",  "...",  "-", "..-", "...-", ".--",  "-..-", "-.--", "--.." };

        unordered_set<string> s;
        int n = words.size(); 

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < words[i].size(); j++) {
                string ch = morse[words[i][j] - 'a'];
                temp += ch;
            }
            s.insert(temp);
        }
        return s.size();
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of words : ";
    cin >> n;

    vector<string> words(n);
    cout <<"Enter the words : ";
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }

    cout <<"Number of unique Morse code representations : " << sol.uniqueMorseRepresentations(words)<< endl;

    return 0;
}