
/* ================================== LeetCode Version ======================================

- Time Complexity: O(N + T) // Where N is the number of people and T is the number of trust pairs.
- Space Complexity: O(N) 

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScores(n + 1, 0);
        for(auto& t : trust){
            trustScores[t[0]]--;  // The person who trusts loses 1 point.
            trustScores[t[1]]++;  // The person being trusted gains 1 point.
        }
        
        for(int i = 1; i <= n; i++)
            // If a person's final score == n - 1, that person is the judge.
            if(trustScores[i] == n - 1) return i;

        return -1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScores(n + 1, 0);
        for(auto& t : trust){
            trustScores[t[0]]--;  // The person who trusts loses 1 point.
            trustScores[t[1]]++;  // The person being trusted gains 1 point.
        }
        
        for(int i = 1; i <= n; i++)
            // If a person's final score == n - 1, that person is the judge.
            if(trustScores[i] == n - 1) return i;

        return -1;
    }
};

int main(){
    Solution sol;
    int n, m;
    
    cout <<"Enter the number of people : ";
    cin >> n;
    
    cout <<"Enter the number of trust relationships : ";
    cin >> m;
    
    vector<vector<int>> trust(m, vector<int>(2));
    cout <<"Enter the pairs (person A trusts person B) :\n";
    for(int i = 0; i < m; i++) {
        cin >> trust[i][0] >> trust[i][1];
    }
    
    int judge = sol.findJudge(n, trust);
    if(judge != -1)
        cout <<"The town judge is : "<< judge << endl;
    else 
        cout <<"There is no town judge."<< endl;
    
    return 0;
}