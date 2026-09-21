
/* ================================== LeetCode Version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(m*n) 

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                    result[i][j] = matrix[j][i];
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
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                    result[i][j] = matrix[j][i];
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int m, n;
    cout <<"Enter the number of rows and columns : ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout <<"Enter the elements of the matrix :"<< endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = sol.transpose(matrix);
    cout <<"The transpose matrix is :"<< endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}