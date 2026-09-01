
/* ================================== LeetCode Version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row - 1; i++){
            for(int j = 0; j < col - 1; j++){
                if(matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
            }
        }
        return true;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row - 1; i++){
            for(int j = 0; j < col - 1; j++){
                if(matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    int m,n;
    cout <<"Enter the number of rows and columns :"<< endl;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout <<"\nEnter the elements of the matrix :"<< endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    cout <<"\nIs it a Toeplitz matrix? : " << (sol.isToeplitzMatrix(matrix) ? "Yes" : "No") << endl;

    return 0;
}