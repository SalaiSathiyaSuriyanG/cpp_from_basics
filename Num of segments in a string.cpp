
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) //n is the length of the string 
- Space Complexity: O(1)

class Solution {
public:
    int countSegments(string s) {
       int count = 0;

       for(int i = 0; i < s.size(); i++){
            if(s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) /*The current character is not a space,and 
            it is either the first character in the string or comes right after a space./
                count++;
       } 
       return count;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
       int count = 0;

       for(int i = 0; i < s.size(); i++){
            if(s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) /*The current character is not a space,and 
            it is either the first character in the string or comes right after a space.*/
                count++;
       } 
       return count;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    getline(cin,s);
    cout <<"Number of segments in the string is : "<<sol.countSegments(s);

    return 0;
}