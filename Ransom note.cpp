
/* ================================== LeetCode version ======================================

- Time Complexity: O(n + m) //Beacuse we scan through both the strings once.
- Space Complexity: O(1)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0}; 

        for(char ch : magazine){
            count[ch - 'a']++;
        }

        for(char ch : ransomNote){
            count[ch - 'a']--;

            //When magazine doesn't have enough characters
            if(count[ch - 'a'] < 0)
                return false;
        }        
        return true;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0}; 

        for(char ch : magazine){
            count[ch - 'a']++;
        }

        for(char ch : ransomNote){
            count[ch - 'a']--;

            //When magazine doesn't have enough characters
            if(count[ch - 'a'] < 0)
                return false;
        }        
        return true;
    }
};

int main(){
    Solution sol;
    string a,b;

    cout << "Enter a string for ransom note (in lowercase) : ";
    cin >> a;
    cout << "Enter a string for magazine (in lowercase) : ";
    cin >> b;

    if(sol.canConstruct(a,b))
        cout <<"Ransom note can be constructed from the magazine.";
    else
        cout <<"Ransom note cannot be constructed from the magazine.";

    return 0;    
}