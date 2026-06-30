
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n) //where m is no.of rows and n is the no.of columns
- Space Complexity: O(r*c) //Because of Reshape matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c) return mat;

        vector<vector<int>> reshape(r,vector<int> (c));
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                reshape[count / c][count % c] = mat[i][j]; 
                count ++;
            }
        }
        return reshape;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c) return mat;

        vector<vector<int>> reshape(r,vector<int> (c));
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                reshape[count / c][count % c] = mat[i][j]; 
                count ++;
            }
        }
        return reshape;
    }
};

int main(){
    Solution sol;
    int m,n,r,c;

    cout <<"Enter the no.of rows and columns of the matrix : ";
    cin >> m >> n;
    vector<vector<int>> mat(m,vector<int> (n));

    cout <<"Enter the elements of the matrix : ";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    cout <<"Enter the no.of rows and columns you want to reshape the matrix into : ";
    cin >> r >> c;

    vector<vector<int>> result = sol.matrixReshape(mat,r,c);

    cout <<"Reshaped matrix : { ";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << result[i][j] <<" ";
        }
    }
    cout <<"} " << endl;

    return 0;
}