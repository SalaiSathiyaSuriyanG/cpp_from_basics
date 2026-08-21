
/* ================================== LeetCode version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(m*n) 

class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int m, int n, int reference_Color){
      
        if(sr < 0 || sr >= m || sc < 0 || sc >= n){
            return;
        }

        //If the neighbouring pixel color differs from the reference colour
        if(image[sr][sc] != reference_Color){
            return;
        }

        //If the neighbouring pixel color matches the reference colour
        image[sr][sc] = color;
        
        dfs(image, sr-1, sc,   color, m, n, reference_Color);  //UP      
        dfs(image, sr+1, sc,   color, m, n, reference_Color);  //Down      
        dfs(image, sr,   sc-1, color, m, n, reference_Color);  //Left  
        dfs(image, sr,   sc+1, color, m, n, reference_Color);  //Right
        }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        int reference_Color = image[sr][sc];
        if(reference_Color == color) {
            return image;
        }

        dfs(image, sr, sc, color, m, n, reference_Color);

        return image;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int m, int n, int reference_Color){
      
        if(sr < 0 || sr >= m || sc < 0 || sc >= n){
            return;
        }

        //If the neighbouring pixel color differs from the reference colour
        if(image[sr][sc] != reference_Color){
            return;
        }

        //If the neighbouring pixel color matches the reference colour
        image[sr][sc] = color;
        
        dfs(image, sr-1, sc,   color, m, n, reference_Color);  //UP      
        dfs(image, sr+1, sc,   color, m, n, reference_Color);  //Down      
        dfs(image, sr,   sc-1, color, m, n, reference_Color);  //Left  
        dfs(image, sr,   sc+1, color, m, n, reference_Color);  //Right
        }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        int reference_Color = image[sr][sc];
        if(reference_Color == color) {
            return image;
        }

        dfs(image, sr, sc, color, m, n, reference_Color);

        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    // Print the result
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}