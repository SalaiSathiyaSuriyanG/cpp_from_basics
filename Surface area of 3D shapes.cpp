
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n^2) //Where n is the size of the grid
- Space Complexity: O(1) 

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int result = 0, n = grid.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // Calculate the max surface area
                if(grid[i][j]) result += (grid[i][j]) * 4 + 2;

                // Subtract the vertical overlap with the tower above the current tower
                if(i != 0) result -= min(grid[i][j], grid[i - 1][j]) * 2; 
                
                // Subtract the horizontal overlap with the tower left to the current tower
                if(j != 0) result -= min(grid[i][j], grid[i][j - 1]) * 2;
            }
        }
        return result;
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
    int surfaceArea(vector<vector<int>>& grid) {
        int result = 0, n = grid.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // Calculate the max surface area
                if(grid[i][j]) result += (grid[i][j]) * 4 + 2;

                // Subtract the vertical overlap with the tower above the current tower
                if(i != 0) result -= min(grid[i][j], grid[i - 1][j]) * 2; 
                
                // Subtract the horizontal overlap with the tower left to the current tower
                if(j != 0) result -= min(grid[i][j], grid[i][j - 1]) * 2;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the size of the grid : ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout <<"Enter the elements of the grid :"<< endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    cout <<"The surface area of the 3D shape is : " << sol.surfaceArea(grid) << endl;

    return 0;
}