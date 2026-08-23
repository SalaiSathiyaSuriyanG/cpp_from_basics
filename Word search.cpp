
/* ================================== LeetCode version ======================================

- Time Complexity: O(n*m*4^k) //Where n is the number of rows, m is the number of columns, 4 represents the directions and k is the length of the word.
- Space Complexity: O(n*m) //For the visited array.

class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board,vector<vector<int>>&vis, string &word, int index){
        int m = board.size();
        int n = board[0].size();

        if(index == word.size()) return true;
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j]==1 || board[i][j] != word[index]) return false; 
        if(vis[i][j] == 1 || board[i][j] != word[index]) return false;

        vis[i][j] = 1;
        bool result = dfs(i,   j-1, board, vis, word, index +1) ||
                   dfs(i,   j+1, board, vis, word, index +1) ||
                   dfs(i-1,   j, board, vis, word, index +1) ||
                   dfs(i+1,   j, board, vis, word, index +1);

        vis[i][j] = 0;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        char initial = word[0]; 
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == initial){
                    vector<vector<int>> vis(m,vector<int>(n,0));

                    if(dfs(i, j, board, vis, word, 0) == true) 
                        return true;
                }
            }
        }
        return false;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board,vector<vector<int>>&vis, string &word, int index){
        int m = board.size();
        int n = board[0].size();

        if(index == word.size()) return true;
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j]==1 || board[i][j] != word[index]) return false; 
        if(vis[i][j] == 1 || board[i][j] != word[index]) return false;

        vis[i][j] = 1;
        bool result = dfs(i,   j-1, board, vis, word, index +1) ||
                   dfs(i,   j+1, board, vis, word, index +1) ||
                   dfs(i-1,   j, board, vis, word, index +1) ||
                   dfs(i+1,   j, board, vis, word, index +1);

        vis[i][j] = 0;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        char initial = word[0]; 
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == initial){
                    vector<vector<int>> vis(m,vector<int>(n,0));

                    if(dfs(i, j, board, vis, word, 0) == true) 
                        return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    int m,n;
    cout <<"Enter the number of rows and columns :"<< endl;
    cin >> m >> n;

    vector<vector<char>> board(m,vector<char>(n));
    cout <<"Enter the elements of the board :"<< endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    string word;
    cout <<"Enter the word to search : ";
    cin >> word;

    cout << (sol.exist(board, word) ? "Word found!" : "Word not found!") << endl;

    return 0;
}