
/* ================================== LeetCode version ======================================

- Time Complexity: O(log(row * col)) 
- Space Complexity: O(1) 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row*col - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int l = mid / col;
            int r = mid % col;

            int result = matrix[l][r];

            if(result == target) return true;

            if(result < target)
                left = mid + 1;

            if(result > target)
                right = mid - 1;    
        }
        return false;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row*col - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int l = mid / col;
            int r = mid % col;

            int result = matrix[l][r];

            if(result == target) return true;

            if(result < target)
                left = mid + 1;

            if(result > target)
                right = mid - 1;    
        }
        return false;
    }
};

int main(){
    Solution sol;
    int row,col,target;

    cout <<"Enter the no.of rows and columns of the matrix: ";
    cin >> row >> col;

    vector<vector<int>> matrix(row,vector<int>(col));

    cout <<"Enter the elements of the matrix : ";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> matrix[i][j];
        }    
    }

    cout <<"Enter the target element : ";
    cin >> target;

    if(sol.searchMatrix(matrix,target))
        cout <<"Target element is present in the matrix.";
    else
        cout <<"Target element is not present in the matrix.";

    return 0;    
}