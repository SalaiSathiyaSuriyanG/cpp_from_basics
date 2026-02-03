
/* ==================== LeetCode version =========================
- Leetcode Problem :  
- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> Val = { {'I',1},{'V',5},
        {'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int result=0;

        for(int i=0;i<s.length();i++){
            if(i+1<s.length() && Val[s[i]]<Val[s[i+1]])
            result -= Val[s[i]];
            else
            result += Val[s[i]];
        }
        return result;
    }
};

=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> Val = {
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };

        int result = 0;

        for(int i = 0; i < s.length(); i++){
            if(i + 1 < s.length() && Val[s[i]] < Val[s[i + 1]])
            result -= Val[s[i]];
            else
            result += Val[s[i]];
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s;
    
    cout<<"Enter a Roman numeral : ";
    cin>>s;
    
    cout<<"Integer equivalent : "<<sol.romanToInt(s)<<endl;    
	 
    return 0;
}