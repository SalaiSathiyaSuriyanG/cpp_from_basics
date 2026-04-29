
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n)
- Space Complexity: O(m*n) //stores all elements in the result vector

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty())
            return result;

        int top = 0,left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        while(top <= bottom && left <= right){
            //Traverse top row
            for(int col = left; col <= right; col++){
                result.push_back(matrix[top][col]);
            }
            top++;

            //Traverse right column
            for(int row = top; row <= bottom; row++){
                result.push_back(matrix[row][right]);
            }
            right--;

            //Traverse bottom row
            if(top <= bottom){
                for(int col = right; col >= left; col--){
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            //Traverse left column
            if(left <= right){
                for(int row = bottom; row >= top; row--){
                    result.push_back(matrix[row][left]);
                }
                left++;
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty() || matrix[0].empty())
            return result;

        int top = 0,left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        while(top <= bottom && left <= right){
            //Traverse top row
            for(int col = left; col <= right; col++){
                result.push_back(matrix[top][col]);
            }
            top++;

            //Traverse right column
            for(int row = top; row <= bottom; row++){
                result.push_back(matrix[row][right]);
            }
            right--;

            //Traverse bottom row
            if(top <= bottom){
                for(int col = right; col >= left; col--){
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            //Traverse left column
            if(left <= right){
                for(int row = bottom; row >= top; row--){
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        } 
        return result;   
    }
};

int main(){
    Solution sol;
    int m,n;

    cout << "Enter the number of rows and columns : ";
    cin >> m >> n;

    vector<vector<int>> matrix(m,vector<int>(n));

    cout <<"Enter matrix elements:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> result = sol.spiralOrder(matrix);

    cout <<"Spiral order : ";
    for(int x : result){
        cout << x <<" ";
    }
    cout <<endl;

    return 0;
}