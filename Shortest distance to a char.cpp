
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n*m) 
- Space Complexity: O(n) //Because we are storing the position of the character in a vector.

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> position;
        vector<int> result;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == c)
                position.push_back(i);
        }

        for(int i = 0; i < s.size(); i++){
            int Min = INT_MAX;
            for(int j = 0; j < position.size(); j++){
                Min = min(Min, abs(i - position[j]));
            }
            result.push_back(Min);
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> position;
        vector<int> result;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == c)
                position.push_back(i);
        }

        for(int i = 0; i < s.size(); i++){
            int Min = INT_MAX;
            for(int j = 0; j < position.size(); j++){
                Min = min(Min, abs(i - position[j]));
            }
            result.push_back(Min);
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter the string : ";
    cin >> s;

    char c;
    cout <<"Enter the character : ";
    cin >> c;

    vector<int> result = sol.shortestToChar(s, c);
    cout <<"The shortest distance to the character '" << c << "' is : ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] <<"  ";
    }
    cout << endl;
    
    return 0;
}