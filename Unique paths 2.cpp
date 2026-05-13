
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n)
- Space Complexity: O(m*n) //We store the m*n grid in the dp array

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m,vector<long long>(n,0)); //No.of ways to reach (i,j)

        if(obstacleGrid[0][0] == 1) //If the starting point has obstacle
            return 0;

        dp[0][0] = 1;   //Starting point

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1)  //To check if the current point is blocked
                    dp[i][j] = 0;  

                else{  //To reach a point, you can only come from top or left
                    if(i > 0)    
                        dp[i][j] += dp[i - 1][j];

                    if(j > 0)
                        dp[i][j] += dp[i][j - 1];    
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m,vector<long long>(n,0)); //No.of ways to reach (i,j)

        if(obstacleGrid[0][0] == 1) //If the starting point has obstacle
            return 0;

        dp[0][0] = 1;   //Starting point

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1)  //To check if the current point is blocked
                    dp[i][j] = 0;  

                else{  //To reach a point, you can only come from top or left
                    if(i > 0)    
                        dp[i][j] += dp[i - 1][j];

                    if(j > 0)
                        dp[i][j] += dp[i][j - 1];    
                }
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

    vector<vector<int>> obstacleGrid(m,vector<int>(n));
    cout <<"Enter the grid (0 for empty cell and 1 for obstacle) : "<<endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> obstacleGrid[i][j];
        }
    }

    cout <<"Number of unique paths without obstacles : "<< sol.uniquePathsWithObstacles(obstacleGrid);

    return 0;
}