
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) //Because of the unordered_set. 

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        
        if(goal.length() != n){
            return false;
        }

        //If both strings are already equal,
        //return true only if there is a duplicate character.
        //Swapping two identical characters keeps the string unchanged.
        if(s == goal){
            unordered_set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); 
        }

        int i = 0;
        int j = n - 1;

        //Skip matching characters from the left.
        //Stop at the first index where s and goal mismatches
        while(i < j && s[i] == goal[i]){
            i++;
        }

        //Skip matching characters from the right.
        //Stop at the last index where s and goal mismatches
        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        //Swap the mismatched characters and check if it makes s == goal
        if(i < j){
            swap(s[i], s[j]);
        }
        return s == goal;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        
        if(goal.length() != n){
            return false;
        }

        //If both strings are already equal,
        //return true only if there is a duplicate character.
        //Swapping two identical characters keeps the string unchanged.
        if(s == goal){
            unordered_set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); 
        }

        int i = 0;
        int j = n - 1;

        //Skip matching characters from the left.
        //Stop at the first index where s and goal mismatches
        while(i < j && s[i] == goal[i]){
            i++;
        }

        //Skip matching characters from the right.
        //Stop at the last index where s and goal mismatches
        while(j >= 0 && s[j] == goal[j]){
            j--;
        }

        //Swap the mismatched characters and check if it makes s == goal
        if(i < j){
            swap(s[i], s[j]);
        }
        return s == goal;
    }
};

int main(){
    Solution sol;
    string s,g;
    cout <<"Enter the first string : ";
    cin >> s;
    cout <<"Enter the second string : ";
    cin >> g;

    if(sol.buddyStrings(s, g))
        cout <<"The strings are buddies." << endl;
    else
        cout <<"The strings are not buddies." << endl;

    return 0;    
}