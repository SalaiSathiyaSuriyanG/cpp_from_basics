
/* ==================== LeetCode version =========================

- Time Complexity: O(n^2) 
- Space Complexity: O(n^2)
  // We scan the board once using constant extra space, 
     so it’s O(n^2) time and O(n^2) space,which reduces to O(1) for a fixed 9×9 Sudoku.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), boxes(9);
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char val = board[i][j];
                
                if (val == '.') 
                continue;
                
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (rows[i].count(val) || 
                    cols[j].count(val) || 
                    boxes[boxIndex].count(val)){
                    return false;
                }
                rows[i].insert(val);
                cols[j].insert(val);
                boxes[boxIndex].insert(val);
            }
        }
        return true;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9), cols(9), boxes(9);
        
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char val = board[i][j];
                
                if (val == '.') 
                continue;
                
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (rows[i].count(val) || 
                    cols[j].count(val) || 
                    boxes[boxIndex].count(val)){
                    return false;
                }
                rows[i].insert(val);
                cols[j].insert(val);
                boxes[boxIndex].insert(val);
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board(9, vector<char>(9));
    
    cout <<"Enter the Sudoku board (9 lines, each with 9 characters): "; 
    for (int i = 0; i < 9; i++){
        string row;
        cin >> row;
        if (row.size() != 9) {
            cout << "Invalid input! Each row must have exactly 9 characters.";
            return 0;
        }

        for (int j = 0; j < 9; j++) {
            board[i][j] = row[j];
        }
    }
    
    if(sol.isValidSudoku(board))
        cout <<"\nValid Sudoku";
    else 
        cout <<"\nInvalid Sudoku";
    
    return 0;
}