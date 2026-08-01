
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(m*n) 

class Solution {
public:    
    int m,n;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        if(visited[i][j]) return;

        visited[i][j] = true;

        for(auto& d : directions){
            //(x, y) represents a neighboring cell
            int x = i + d[0];
            int y = j + d[1];

            //Skip if it's out of the grid
            if(x < 0 || x >= m || y < 0 || y >= n) continue;  

            //Skip if the neighbor has already been visited
            if(visited[x][y]) continue; 

            /*Since we're performing Reverse DFS, skip if the neighbor cell's height < current dfs cell's height /
            if(heights[x][y] < heights[i][j]) continue;  

            dfs(x, y, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        //Initialize all cells as False
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        //Start DFS from all cells on the Pacific Ocean borders:
        //Left column (col = 0)
        for(int i = 0; i < m; i++) dfs(i, 0, heights, pacific);

        //Top row (row = 0)
        for(int j = 0; j < n; j++) dfs(0, j, heights, pacific);   

        //Start DFS from all cells on the Atlantic Ocean borders:
        //Right column (col = n - 1)
        for(int i = 0; i < m; i++) dfs(i, n-1, heights, atlantic);

        //Bottom row (row = m - 1)
        for(int j = 0; j < n; j++) dfs(m-1, j, heights, atlantic); 

        vector<vector<int>> result;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //Check if the current cell (i,j) reaches both oceans
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
            }
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
    int m,n;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        if(visited[i][j]) return;

        visited[i][j] = true;

        for(auto& d : directions){
            //(x, y) represents a neighboring cell
            int x = i + d[0];
            int y = j + d[1];

            //Skip if it's out of the grid
            if(x < 0 || x >= m || y < 0 || y >= n) continue;  

            //Skip if the neighbor has already been visited
            if(visited[x][y]) continue; 

            /*Since we're performing Reverse DFS, skip if the neighbor cell's height < current dfs cell's height*/
            if(heights[x][y] < heights[i][j]) continue;  

            dfs(x, y, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        //Initialize all cells as False
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        //Start DFS from all cells on the Pacific Ocean borders:
        //Left column (col = 0)
        for(int i = 0; i < m; i++) dfs(i, 0, heights, pacific);

        //Top row (row = 0)
        for(int j = 0; j < n; j++) dfs(0, j, heights, pacific);   

        //Start DFS from all cells on the Atlantic Ocean borders:
        //Right column (col = n - 1)
        for(int i = 0; i < m; i++) dfs(i, n-1, heights, atlantic);

        //Bottom row (row = m - 1)
        for(int j = 0; j < n; j++) dfs(m-1, j, heights, atlantic); 

        vector<vector<int>> result;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //Check if the current cell (i,j) reaches both oceans
                if(pacific[i][j] && atlantic[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int m,n;

    cout <<"Enter the number of rows and columns : "<< endl;
    cin >> m >> n;

    vector<vector<int>> heights(m, vector<int>(n));
    cout <<"Enter the heights of the cells : "<< endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> heights[i][j];
        }
    }

    vector<vector<int>> result = sol.pacificAtlantic(heights);
    cout <<"[  ";
    for(auto& cell : result){
        cout <<"["<< cell[0] <<", "<< cell[1] <<"]  ";
    }
    cout <<"]"<< endl;

    return 0;
}