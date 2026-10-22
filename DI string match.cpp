
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) //Because we are using a vector to store the result. 

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> result;

        int inc = 0, dec = n;
        for(char ch : s){
            if(ch == 'I'){
                result.push_back(inc);
                inc++;
            }
            if(ch == 'D'){
                result.push_back(dec);
                dec--;
            }
        }
        result.push_back(dec);
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> result;

        int inc = 0, dec = n;
        for(char ch : s){
            if(ch == 'I'){
                result.push_back(inc);
                inc++;
            }
            if(ch == 'D'){
                result.push_back(dec);
                dec--;
            }
        }
        result.push_back(dec);
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"I => Increase, D => Decrease"<< endl;
    cout <<"\nEnter a string : ";
    cin >> s;

    vector<int> result = sol.diStringMatch(s);
    cout <<"The result is : ";
    for(int i : result){
        cout << i <<" ";
    }
    cout << endl;
    
    return 0;
}