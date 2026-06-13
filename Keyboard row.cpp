
/* ================================== LeetCode version ======================================

- Time Complexity: O(n*m) //n is the number of words and m is the average length of the words. 
- Space Complexity: O(1) 

/*Explanation :
Pick the row of the first letter as the "reference row." 
Then verify whether every other letter belongs to the same row. 
If any letter belongs to a different row,reject the word./

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> row;
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";

        vector<string> result;

        for(char c1 : r1) row[c1] = 1;
        for(char c2 : r2) row[c2] = 2;
        for(char c3 : r3) row[c3] = 3;

        for(string word : words){
            //Use the first character to determine which row the entire word should belong to.
            int targetRow = row[tolower(word[0])]; 
            bool validity = true;

            //Check whether every character belongs to the same keyboard row.
            for(char c : word){
                if(row[tolower(c)] != targetRow){
                    validity = false;
                    break;
                }    
            }

            if(validity)
                result.push_back(word);
        }
        return result;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> row;
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";

        vector<string> result;

        for(char c1 : r1) row[c1] = 1;
        for(char c2 : r2) row[c2] = 2;
        for(char c3 : r3) row[c3] = 3;

        for(string word : words){
            //Use the first character to determine which row the entire word should belong to.
            int targetRow = row[tolower(word[0])]; 
            bool validity = true;

            //Check whether every character belongs to the same keyboard row.
            for(char c : word){
                if(row[tolower(c)] != targetRow){
                    validity = false;
                    break;
                }    
            }

            if(validity)
                result.push_back(word);
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
    cout <<"Enter the words : ";
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }

    cout <<"Words that can be typer using one row of the keyboard are : [  ";
    vector<string> result = sol.findWords(words);
    for(string word : result){
        cout << word <<"  ";
    }
    cout <<"]"<< endl;

    return 0;
}