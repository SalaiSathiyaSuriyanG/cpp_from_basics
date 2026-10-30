
/* ================================== LeetCode Version ======================================

- Time Complexity: O(64) 
- Space Complexity: O(1) 

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int R_x = 0, R_y = 0, result = 0;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    R_x = i;
                    R_y = j;
                }
            }
        }
                                       //{Down}, {Right}, {Up}, {Left}
        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0, -1}};
        for(auto& d : directions){
            for(int X = R_x + d[0], Y = R_y + d[1]; (0 <= X && X < 8) && (0 <= Y && Y < 8); X += d[0], Y += d[1]){
                if(board[X][Y] == 'p') result++;
                if(board[X][Y] != '.') break;
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
    int numRookCaptures(vector<vector<char>>& board) {
        int R_x = 0, R_y = 0, result = 0;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    R_x = i;
                    R_y = j;
                }
            }
        }
                                       //{Down}, {Right}, {Up}, {Left}
        vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0, -1}};
        for(auto& d : directions){
            for(int X = R_x + d[0], Y = R_y + d[1]; (0 <= X && X < 8) && (0 <= Y && Y < 8); X += d[0], Y += d[1]){
                if(board[X][Y] == 'p') result++;
                if(board[X][Y] != '.') break;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board(8, vector<char>(8));
    
    cout <<"R = Rook, p = Pawn, . = empty space\n";
    cout <<"Enter the chess board pieces :\n";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> board[i][j];
        }
    }

    cout <<"\nNumber of Pawns the White rook can attack is : "<< sol.numRookCaptures(board) << endl;

    return 0;
}