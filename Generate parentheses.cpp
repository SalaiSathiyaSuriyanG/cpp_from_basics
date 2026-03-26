
/* ==================== LeetCode version =========================

- Time Complexity: O(4^n/√n) // The number of valid parentheses combinations is given by 
                                  the nth Catalan number, which is approximately O(4^n/√n).
- Space Complexity: O(n) // The maximum depth of the recursion is n, which occurs 
                            when we have n open parentheses before any close parentheses.

class Solution {
public:
    vector<string> result;  // global

    void algorithm(string current,int open,int close,int n){
        if(current.size() == 2*n){
            result.push_back(current);
            return; // stops adding parentheses when the condition is met
        }
        if(open < n)
        algorithm(current + "(", open + 1, close, n);

        if(close < open)
        algorithm(current + ")", open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        algorithm("",0,0,n);
        return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;  // global

    void algorithm(string current,int open,int close,int n){
        if(current.size() == 2*n){
            result.push_back(current);
            return; // stops adding parentheses when the condition is met
        }
        if(open < n)
        algorithm(current + "(", open + 1, close, n);

        if(close < open)
        algorithm(current + ")", open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        algorithm("",0,0,n);
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of pairs of parentheses: ";
    cin >> n;
    vector<string> combinations = sol.generateParenthesis(n);
    
    cout <<"All combinations of parentheses are : ";
    for (int i = 0; i < combinations.size(); i++){
    cout << combinations[i] << "   ";
    }

    return 0;
}