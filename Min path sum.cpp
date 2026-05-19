
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n)
- Space Complexity: O(m*n) //We store the m*n grid in the dp array

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];  //Starting point

        //First row (can only come from left)
        for(int j = 1; j < n; j++){
            dp[0][j] = dp[0][j - 1] + grid[0][j]; 
        }

        //First column (can only come from top)
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        //For other cells
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0];  //Starting point

        //First row (can only come from left)
        for(int j = 1; j < n; j++){
            dp[0][j] = dp[0][j - 1] + grid[0][j]; 
        }

        //First column (can only come from top)
        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        //For other cells
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(){
    Solution sol;
    int m,n;
    cout <<"Enter the number of rows and columns : ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n,0));

    cout <<"Enter the grid values : "<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout <<"Minimum path sum is : "<< sol.minPathSum(grid);

    return 0;
}