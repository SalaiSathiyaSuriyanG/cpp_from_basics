
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(1) 

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){  
                    /*Process only land cells.
                    Assume this land cell is isolated.
                    An isolated square contributes 4 sides./
                    perimeter += 4;

                    /*We check only Above and Left cells because,
                    right and bottom cells haven't been processed yet./
                    if(i > 0 && grid[i - 1][j] == 1)
                        perimeter -= 2;

                    if(j > 0 && grid[i][j - 1] == 1)
                        perimeter -= 2;
                }    
            }
        }
        return perimeter;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){  
                    /*Process only land cells.
                    Assume this land cell is isolated.
                    An isolated square contributes 4 sides.*/
                    perimeter += 4;

                    /*We check only Above and Left cells because,
                    right and bottom cells haven't been processed yet.*/
                    if(i > 0 && grid[i - 1][j] == 1)
                        perimeter -= 2;

                    if(j > 0 && grid[i][j - 1] == 1)
                        perimeter -= 2;
                }    
            }
        }
        return perimeter;
    }
};

int main(){
    Solution sol;
    int m,n;
    cout <<"Enter the number of rows and columns : ";
    cin >> m >> n;

    vector<vector<int>> grid(m,vector<int>(n));
    cout <<"Enter the grid (0 for water and 1 for land) : ";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    cout <<"The perimeter of the island is : " << sol.islandPerimeter(grid);

    return 0;
}