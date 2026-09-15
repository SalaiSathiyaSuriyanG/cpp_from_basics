
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        vector<vector<int>> result;
        int i = 0, j = 0, len = 0;

        while(i < n && j <= n){
            if(j < n && s[i] == s[j]) j++;

            else{
                len = j - i;

                if(len >= 3){
                    result.push_back({i, j - 1});
                }
                i = j;
                j++;
            }
        }
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
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        vector<vector<int>> result;
        int i = 0, j = 0, len = 0;

        while(i < n && j <= n){
            if(j < n && s[i] == s[j]) j++;

            else{
                len = j - i;

                if(len >= 3){
                    result.push_back({i, j - 1});
                }
                i = j;
                j++;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    cin >> s;

    vector<vector<int>> result = sol.largeGroupPositions(s);

    cout <<"Large group positions : ";
    for(auto &group : result){
        cout << "[" << group[0] << ", " << group[1] << "]" << endl;
    }

    return 0;
}