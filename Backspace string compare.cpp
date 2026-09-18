
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n + m) //Where n and m are the lengths of the strings s and t respectively
- Space Complexity: O(1) 

class Solution {
private:
    string helper(string st){
        int count = 0;

        for(char ch : st){
            if(ch == '#'){
                if(count > 0)
                    count--;
            }
            else{
                st[count] = ch;
                count++;
            } 
        }
        return st.substr(0,count);
    }

public:
    bool backspaceCompare(string s, string t) {
        return helper(s) == helper(t);
    }    
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    string helper(string st){
        int count = 0;

        for(char ch : st){
            if(ch == '#'){
                if(count > 0)
                    count--;
            }
            else{
                st[count] = ch;
                count++;
            } 
        }
        return st.substr(0,count);
    }

public:
    bool backspaceCompare(string s, string t) {
        return helper(s) == helper(t);
    }    
};

int main(){
    Solution sol;
    string s, t;
    cout <<"Enter two strings to compare :"<< endl;
    cin >> s >> t;
    
    if(sol.backspaceCompare(s, t))
        cout <<"The strings are equal after processing backspaces."<< endl;
    
    else 
        cout <<"The strings are not equal after processing backspaces."<< endl;

    return 0;
}