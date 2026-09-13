
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) 

class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string toGoatLatin(string s) {
        stringstream ss(s);
        string word, result;
        string a = "a";

        while (ss >> word) {
            if (isVowel(word[0])){
                word += "ma";
            } 
            else{
                word = word.substr(1) + word[0] + "ma";
            }

            word += a;
            a += "a";

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
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string toGoatLatin(string s) {
        stringstream ss(s);
        string word, result;
        string a = "a";

        while (ss >> word) {
            if (isVowel(word[0])){
                word += "ma";
            } 
            else{
                word = word.substr(1) + word[0] + "ma";
            }

            word += a;
            a += "a";

            result += word + " ";
        }
        result.pop_back(); 
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a sentence : ";
    getline(cin, s);

    cout <<"Goat Latin : "<< sol.toGoatLatin(s) << endl;

    return 0;
}