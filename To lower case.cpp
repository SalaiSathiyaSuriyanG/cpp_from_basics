
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    string toLowerCase(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;      //Uppercase + 32 gives Lowercase
        }
        return s;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;      //Uppercase + 32 gives Lowercase
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    getline(cin, s);

    cout <<"String in lower case : "<< sol.toLowerCase(s);

    return 0;
}