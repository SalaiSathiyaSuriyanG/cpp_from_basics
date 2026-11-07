
/* ================================== LeetCode Version ======================================

- Time Complexity: O(m * n)  
- Space Complexity: O(m * n) //We are using a set to keep track of visited cells.

class Solution {
    int flag = 1;
    set<pair<int, int>> currGroup;
    set<pair<int, int>> globalVisited;

private:
    void dfs(vector<vector<char>>& board, int i, int j){
        // Check for out of bounds or if already visited or if the letter is 'X'
        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size() ||
           globalVisited.contains({i, j}) || board[i][j] == 'X') return;

        // If not visited before, mark as visited
        currGroup.insert({i, j});
        globalVisited.insert({i, j});

        // If it's on the edge, mark the flag
        if(i == 0 || i == board.size() - 1 ||
           j == 0 || j == board[0].size() - 1) flag = 0;
        
        dfs(board, i + 1, j);   // Down
        dfs(board, i, j + 1);   // Right
        dfs(board, i - 1, j);   // Up
        dfs(board, i, j - 1);   // Left
    }

public:
    void solve(vector<vector<char>>& board) {

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // Only start DFS if it's an 'O' and hasn't been globally visited
                if(board[i][j] == 'O' && !globalVisited.contains({i, j})){
                    flag = 1;
                    dfs(board, i, j);
                    
                    // After looking through all 4 directions,
                    // if the flag is still 1, it means the entire group is completely 
                    // surrounded (none of its cells touched the board's edge).
                    // Therefore, we safely flip all 'O's in this group to 'X'.
                    if(flag){
                        for(auto it : currGroup){
                            board[it.first][it.second] = 'X';
                        }
                    }
                    currGroup.clear();
                }
            }
        }
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

class Solution {
    int flag = 1;
    set<pair<int, int>> currGroup;
    set<pair<int, int>> globalVisited;

private:
    void dfs(vector<vector<char>>& board, int i, int j){
        // Check for out of bounds or if already visited or if the letter is 'X'
        if(i < 0 || i >= board.size() ||
           j < 0 || j >= board[0].size() ||
           globalVisited.contains({i, j}) || board[i][j] == 'X') return;

        // If not visited before, mark as visited
        currGroup.insert({i, j});
        globalVisited.insert({i, j});

        // If it's on the edge, mark the flag
        if(i == 0 || i == board.size() - 1 ||
           j == 0 || j == board[0].size() - 1) flag = 0;
        
        dfs(board, i + 1, j);   // Down
        dfs(board, i, j + 1);   // Right
        dfs(board, i - 1, j);   // Up
        dfs(board, i, j - 1);   // Left
    }

public:
    void solve(vector<vector<char>>& board) {

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // Only start DFS if it's an 'O' and hasn't been globally visited
                if(board[i][j] == 'O' && !globalVisited.contains({i, j})){
                    flag = 1;
                    dfs(board, i, j);
                    
                    // After looking through all 4 directions,
                    // if the flag is still 1, it means the entire group is completely 
                    // surrounded (none of its cells touched the board's edge).
                    // Therefore, we safely flip all 'O's in this group to 'X'.
                    if(flag){
                        for(auto it : currGroup){
                            board[it.first][it.second] = 'X';
                        }
                    }
                    currGroup.clear();
                }
            }
        }
    }
};

int main(){
    Solution sol;
    int m, n;
    cout <<"Enter the number of rows and columns :\n";
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));
    cout <<"Enter the board elements (O or X) :\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    cout <<"\nOriginal Board:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] <<" ";
        }
        cout << endl;
    }

    cout <<"\nAfter replacing surrounded regions :\n";
    sol.solve(board);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}