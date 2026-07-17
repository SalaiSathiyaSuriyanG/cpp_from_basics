
/* ==================== LeetCode version =========================

- Time Complexity: O(2^target (roughly)) // In the worst case, the number of combinations 
                                           can grow exponentially with the target value. 

- Space Complexity: O(target) // The maximum depth of the recursion can be equal to the 
                                 target value in the worst case.

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, 
    vector<int>& current, vector<vector<int>>& result){

        if(target == 0){
            result.push_back(current);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target)
                break;
              
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> current;
        vector<vector<int>> result;

        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, 
    vector<int>& current, vector<vector<int>>& result){

        if(target == 0){
            result.push_back(current);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target)
                break;
              
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> current;
        vector<vector<int>> result;

        backtrack(candidates, target, 0, current, result);
        return result;
    }
};

int main(){
    Solution sol;
    int n,target;
    cout <<"Enter the number of candidates: ";
    cin >> n;

    vector<int> candidates(n);
    cout <<"Enter the candidates : ";
    for(int i = 0; i < n; i++){
        cin >> candidates[i];
    }
    cout <<"Enter the target : ";
    cin >> target;

    vector<vector<int>> result = sol.combinationSum(candidates, target);
    cout <<"Combinations that sum up to " << target << " are : ";

    for(const auto& combo : result){
        cout <<"[";
        for(int j = 0; j < combo.size(); j++){
            cout << combo[j];
            if(j < combo.size() - 1)
                cout <<",";
        }
        cout << "]  ";
    }

    return 0;
}