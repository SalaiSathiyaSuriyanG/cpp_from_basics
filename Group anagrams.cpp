
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string str : strs){
            string key = str;
            sort(key.begin(),key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& pair : map){
            result.push_back(pair.second); //.second gives the value of the respective key
        }

        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string str : strs){
            string key = str;
            sort(key.begin(),key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto& pair : map){
            result.push_back(pair.second); //.second gives the value of the respective key
        }

        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout <<"Enter the strings : "<<endl;
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }

    vector<vector<string>> result = sol.groupAnagrams(strs);
    cout <<"Grouped anagrams : "<<endl;
    for (const auto& group : result){
        cout <<"[ ";
        for (const auto& word : group) {
            cout << word <<" ";
    }
    cout <<"] "; 
    }

    return 0;
}