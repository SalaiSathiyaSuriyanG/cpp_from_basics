
/* ================================== LeetCode version ======================================

- Time Complexity: O(n^2)
- Space Complexity: O(n^2) O(1(auxiliary space)) //O(n^2) for n*n matrix and O(1) for extra space variable(num)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        if(n == 0)
            return matrix;

        int top = 0,left = 0;
        int bottom = n - 1;
        int right = bottom;
        int num = 1;

        while(top <= bottom && left <= right){
            //Traverse from left -> right
            for(int col = left; col <= right; col++){
                matrix[top][col] = num++;
            }
            top++;

            //Traverse from top -> bottom
            for(int row = top; row <= bottom; row++){
                matrix[row][right] = num++;
            }
            right--;

            //Traverse from right -> left
            if(top <= bottom){
                for(int col = right; col >= left; col--){
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }

            //Traverse from bottom -> top
            if(left <= right){
                for(int row = bottom; row >= top; row--){
                    matrix[row][left] = num++;
                }
                left++;
            }
        }    
        return matrix;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        if(n == 0)
            return matrix;

        int top = 0,left = 0;
        int bottom = n - 1;
        int right = bottom;
        int num = 1;

        while(top <= bottom && left <= right){
            //Traverse from left -> right
            for(int col = left; col <= right; col++){
                matrix[top][col] = num++;
            }
            top++;

            //Traverse from top -> bottom
            for(int row = top; row <= bottom; row++){
                matrix[row][right] = num++;
            }
            right--;

            //Traverse from right -> left
            if(top <= bottom){
                for(int col = right; col >= left; col--){
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }

            //Traverse from bottom -> top
            if(left <= right){
                for(int row = bottom; row >= top; row--){
                    matrix[row][left] = num++;
                }
                left++;
            }
        }    
        return matrix;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the size of the matrix (n x n) : ";
    cin >> n;

    vector<vector<int>> result = sol.generateMatrix(n);
    
    cout << "Generated Spiral Matrix : "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}