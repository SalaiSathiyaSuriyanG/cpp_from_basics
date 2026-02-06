
/* ==================== LeetCode version =========================
- Leetcode Problem :  
- Time Complexity: O(n)
- Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;

        for(char ch : s){
            if(ch=='(' || ch=='[' || ch=='{' )
            sta.push(ch);
            
            else{
            if(sta.empty())
            return false;
            char top=sta.top();
            sta.pop();

             if((ch==')' && top!='(') || (ch==']' && top!='[') ||
               (ch=='}' && top!='{'))
               return false;
            }
        }
        return sta.empty();
    }
};

=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
            sta.push(ch);
            } else {
                if (sta.empty())
                return false;

                char top = sta.top();
                sta.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{'))
                return false;
            }
        }
        return sta.empty();
    }
};

int main() {
    Solution sol;
    string s;
    
    cout<<"Enter a Set of Parentheses : ";
    cin>>s;

    if (sol.isValid(s))
    cout<<"Valid Parentheses\n";
    else
    cout<<"Invalid\n";
    
    return 0;
}