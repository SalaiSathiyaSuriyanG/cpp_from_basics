
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n^2) //Where n is the number of rows in the triangle. 
- Space Complexity: O(1) 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; i--){  //Start from row before the last row and move upwards.
            for(int j = 0; j < triangle[i].size(); j++){
                int below = triangle[i + 1][j];
                int belowRight = triangle[i + 1][j + 1];

                triangle[i][j] += min(below, belowRight);
            }
        }
        return triangle[0][0];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; i--){  //Start from row before the last row and move upwards.
            for(int j = 0; j < triangle[i].size(); j++){
                int below = triangle[i + 1][j];
                int belowRight = triangle[i + 1][j + 1];

                triangle[i][j] += min(below, belowRight);
            }
        }
        return triangle[0][0];
    }
};

int main(){
    Solution sol;
    int n;

    cout <<"Enter the number of rows in the triangle : ";
    cin >> n;

    vector<vector<int>> triangle(n);
    cout <<"Enter the elements of the triangle row by row :\n";
    for(int i = 0; i < n; i++){
        triangle[i].resize(i + 1);
        for(int j = 0; j <= i; j++){
            cin >> triangle[i][j];
        }
    }
    
    cout <<"The minimum path sum is : "<< sol.minimumTotal(triangle) << endl;
    
    return 0;
}