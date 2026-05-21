
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;

        for(char ch : s){
            result ^= ch;
        }

        for(char ch : t){
            result ^= ch;
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;

        for(char ch : s){
            result ^= ch;
        }

        for(char ch : t){
            result ^= ch;
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s,t;
    cout << "Enter string 1 : ";
    cin >> s;
    cout <<"Enter string 2 : ";
    cin >> t;
    cout <<"The added letter is "<<"'"<< sol.findTheDifference(s,t)<<"'";
    
    return 0;
}