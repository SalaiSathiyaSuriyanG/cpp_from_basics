
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(m*n) 

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols,0));

        // Iterate through every cell in the image
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int sum = 0;
                int count = 0;

                // Iterate through the 3x3 neighborhood around (r, c)
                for (int nr = r - 1; nr <= r + 1; nr++) {
                    for (int nc = c - 1; nc <= c + 1; nc++) {
                        // Check if the neighboring cell is within bounds
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }
                // Calculate the floor of the average
                result[r][c] = sum / count;
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
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> result(rows, vector<int>(cols,0));

        // Iterate through every cell in the image
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int sum = 0;
                int count = 0;

                // Iterate through the 3x3 neighborhood around (r, c)
                for (int nr = r - 1; nr <= r + 1; nr++) {
                    for (int nc = c - 1; nc <= c + 1; nc++) {
                        // Check if the neighboring cell is within bounds
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }
                // Calculate the floor of the average
                result[r][c] = sum / count;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    int rows = 3, cols = 3;

    vector<vector<int>> img(rows, vector<int>(cols));
    cout <<"-------- 3x3 Image Smoother --------"<< endl;
    cout <<"Enter the image values : "<< endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> img[i][j];
        }
    }

    vector<vector<int>> result = sol.imageSmoother(img);

    cout <<"Smoothed Image : "<< endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}