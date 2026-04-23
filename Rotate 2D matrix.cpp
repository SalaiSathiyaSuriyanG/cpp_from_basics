
/* ================================== LeetCode version ======================================

- Time Complexity: O(n^2)
- Space Complexity: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            int left = 0;
            int right = n - 1;
            while(left < right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
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
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            int left = 0;
            int right = n - 1;
            while(left < right){
                swap(matrix[i][left],matrix[i][right]);
                left++;
                right--;
            }  
        }  
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the matrix size : ";
    cin >> n;

    vector<vector<int>> matrix(n,vector<int>(n));
    cout <<"Enter the elements of the matrix : "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    sol.rotate(matrix);
    cout <<"Rotated matrix : "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout <<endl;
    }
    
    return 0;
}