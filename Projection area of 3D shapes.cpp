
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n^2) //Because we are traversing the grid of size n x n.
- Space Complexity: O(1) 

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
       int result = 0;

       for(int i = 0; i < grid.size(); i++){
        int m = 0, n = 0;
        for(int j = 0; j < grid.size(); j++){
            if(grid[i][j]) result++;
            if(grid[i][j] > m) m = grid[i][j];
            if(grid[j][i] > n) n = grid[j][i];
        }
        result += m + n;
       }
       return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
       int result = 0;
       
       for(int i = 0; i < grid.size(); i++){
        int m = 0, n = 0;
        for(int j = 0; j < grid.size(); j++){
            if(grid[i][j]) result++;
            if(grid[i][j] > m) m = grid[i][j];
            if(grid[j][i] > n) n = grid[j][i];
        }
        result += m + n;
       }
       return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the size of the grid (N x N) : ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout <<"Enter the elements of the grid row-wise : "<< endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    cout <<"The projection area of the grid is : " << sol.projectionArea(grid) << endl;

    return 0;
}