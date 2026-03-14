
/* ==================== LeetCode version =========================

- Time Complexity: O(1) //The no.of iterations is constant as there are only 13 symbols in Roman
- Space Complexity: O(1)

class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {
            1000,900,500,400,100,90,50,40,10,9,5,4,1
            };
        vector<string> symb = {
            "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"
            };
        string result = "";

        for(int i = 0;i<val.size();i++){
            while(num >= val[i]){
                result += symb[i];
                num -= val[i];
            }    
        }
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
    string intToRoman(int num) {
        vector<int> val = {
            1000,900,500,400,100,90,50,40,10,9,5,4,1
            };
        vector<string> symb = {
            "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"
            };
        string result = "";

        for(int i = 0;i<val.size();i++){
            while(num >= val[i]){
                result += symb[i];
                num -= val[i];
            }    
        }
        return result;
    }
};

int main(){
    Solution sol;
    int num;
    cout<<"Enter an integer : ";
    cin >> num;
    cout << "Equivalent Roman number : "<<sol.intToRoman(num);

    return 0;
}