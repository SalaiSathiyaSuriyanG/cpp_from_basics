
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(m*n) //In the worst case when the grid is filled with lands.

class Solution {
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';
        eraseIslands(grid, i, j + 1); //Right
        eraseIslands(grid, i, j - 1); //Left
        eraseIslands(grid, i + 1, j); //Up
        eraseIslands(grid, i - 1, j); //Down
    }    

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0; //To handle empty grid
        int islands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    eraseIslands(grid, i ,j);
                }    
            }
        }
        return islands;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';
        eraseIslands(grid, i, j + 1); //Right
        eraseIslands(grid, i, j - 1); //Left
        eraseIslands(grid, i + 1, j); //Up
        eraseIslands(grid, i - 1, j); //Down
    }    

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0; //To handle empty grid
        int islands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    eraseIslands(grid, i ,j);
                }    
            }
        }
        return islands;
    }
};

int main(){
    Solution sol;
    int m,n;
    cout <<"Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    cout <<"Enter the grid (0s and 1s) : "<< endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    cout <<"Number of island(s) : " << sol.numIslands(grid);

    return 0;
}