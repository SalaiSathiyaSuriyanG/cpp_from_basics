
/* ================================== LeetCode Version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(1) 

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        int c = strs[0].size();
        int del = 0;

        for(int i = 0; i < c; i++){
            for(int j = 1; j < r; j++){
                if(strs[j][i] < strs[j - 1][i]){
                    del++;
                    break;
                }
            }
        }
        return del;
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
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        int c = strs[0].size();
        int del = 0;

        for(int i = 0; i < c; i++){
            for(int j = 1; j < r; j++){
                if(strs[j][i] < strs[j - 1][i]){
                    del++;
                    break;
                }
            }
        }
        return del;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of strings : ";
    cin >> n;

    vector<string> strs(n);
    cout <<"Enter the strings :" << endl;
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }

    cout <<"\nNumber of column(s) to be deleted : "<< sol.minDeletionSize(strs) << endl;

    return 0;
}