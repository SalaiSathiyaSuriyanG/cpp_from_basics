
/* ================================== LeetCode Version ======================================

- Time Complexity: O(k * (n choose k)) 
- Space Complexity: O(k * (n choose k)) 

class Solution {
private:
    void backtrack(int start, vector<int>& comb, int n, int k, vector<vector<int>>& result){
        if(comb.size() == k){
            result.push_back(comb);
            return;
        }
        for(int i = start; i <= n; i++){          
            comb.push_back(i);
            backtrack(i + 1, comb, n, k, result);
            comb.pop_back();                
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;

        backtrack(1, combination, n, k, result);
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(int start, vector<int>& comb, int n, int k, vector<vector<int>>& result){
        if(comb.size() == k){
            result.push_back(comb);
            return;
        }
        for(int i = start; i <= n; i++){          
            comb.push_back(i);
            backtrack(i + 1, comb, n, k, result);
            comb.pop_back();                
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;

        backtrack(1, combination, n, k, result);
        return result;
    }
};

int main(){
    Solution  sol;
    int n ,k;
    cout <<"Enter the range (1 to n) : ";
    cin >> n;
    cout <<"Enter the size of each combination (k) : ";
    cin >> k;
    
    vector<vector<int>> result = sol.combine(n, k);

    cout <<"The combinations are :"<< endl;
    cout <<"["<< endl;
    for(int i = 0; i < result.size(); i++){
        cout <<"[ ";
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] <<" ";
        }
        cout <<"]"<< endl;
    }
    cout <<"]"<< endl;

    return 0;
}