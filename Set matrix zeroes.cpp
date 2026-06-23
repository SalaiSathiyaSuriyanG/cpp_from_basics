
/* ================================== LeetCode version ======================================

- Time Complexity: O(m * n) //Where m is the no.of rows and n is the no. of columns 
- Space Complexity: O(1) 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zero_inFirstcol = false;
        for (int row = 0; row < matrix.size(); row++){
            if (matrix[row][0] == 0) 
                zero_inFirstcol = true;
            for (int col = 1; col < matrix[0].size(); col++){
                if (matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = matrix.size() - 1; row >= 0; row--){
            for (int col = matrix[0].size() - 1; col >= 1; col--){
                if (matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
            if (zero_inFirstcol){
                matrix[row][0] = 0;
            }
        }
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zero_inFirstcol = false;
        for (int row = 0; row < matrix.size(); row++){
            if (matrix[row][0] == 0) 
                zero_inFirstcol = true;
            for (int col = 1; col < matrix[0].size(); col++){
                if (matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = matrix.size() - 1; row >= 0; row--){
            for (int col = matrix[0].size() - 1; col >= 1; col--){
                if (matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
            if (zero_inFirstcol){
                matrix[row][0] = 0;
            }
        }
    }
};

int main(){
    Solution sol;
    int m,n;
    cout <<"Enter the number of rows : ";
    cin >> m;
    cout <<"Enter the number of columns : ";
    cin >> n;

    vector<vector<int>> matrix(m,vector<int> (n));
    cout <<"Enter the elements of the matrix : ";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];  
        }
    }

    cout <<"Original matrix : "<< endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }

    sol.setZeroes(matrix);
    cout <<"Matrix after setting zeroes : " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}