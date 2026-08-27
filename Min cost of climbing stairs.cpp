
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i = 2; i < n; i++){
            cost[i] += min(cost[i - 1], cost[i - 2]); 
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i = 2; i < n; i++){
            cost[i] += min(cost[i - 1], cost[i - 2]); 
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of steps : ";
    cin >> n;

    vector<int> cost(n);
    cout <<"Enter the cost for each step : ";
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }

    cout <<"Minimum cost to reach the top : " << sol.minCostClimbingStairs(cost) << endl;

    return 0;
}