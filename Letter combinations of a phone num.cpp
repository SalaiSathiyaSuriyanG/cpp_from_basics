
/* =============================== LeetCode version =====================================

- Time Complexity: O(4^n * n) // There are up to 4^n combinations in the worst case 
                                 and each combination takes O(n) time to construct.
- Space Complexity: O(4^n * n) // We store up to 4^ncombinations, each of length n.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return {};
        vector<string> result = {""};

        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        for(char digit : digits){
            vector<string> temp;
            string letters = mapping[digit - '0'];

            for(string combinations : result){
                for(char ch : letters){
                    temp.push_back(combinations + ch);
                }
            }
            result = temp;
        }
        return result;
    }
};
======================================================================================== */

// ============================== Runnable Version ========================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return {};
        vector<string> result = {""};

        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        for(char digit : digits){
            vector<string> temp;
            string letters = mapping[digit - '0'];

            for(string combinations : result){
                for(char ch : letters){
                    temp.push_back(combinations + ch);
                }
            }
            result = temp;
        }
        return result;
    }
};

int main(){
    Solution sol;
    string digits;
    cout <<"Enter the digits (2-9) : ";
    cin >> digits;

    vector<string> result = sol.letterCombinations(digits);
    cout << "Letter combinations: {"; 
    for(const string& s : result){
        cout <<s<<" ";
    }
    cout << "}" << endl;

    return 0;
}