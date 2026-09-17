
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n*n) 
- Space Complexity: O(1) 

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
       int n = image.size();

       for(int i = 0; i < n; i++){
        reverse(image[i].begin(), image[i].end());

        for(int j = 0; j < n; j++){
            if(image[i][j] == 0) image[i][j] = 1;

            else image[i][j] = 0;
        }
       }
       return image;
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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
       int n = image.size();

       for(int i = 0; i < n; i++){
        reverse(image[i].begin(), image[i].end());

        for(int j = 0; j < n; j++){
            if(image[i][j] == 0) image[i][j] = 1;

            else image[i][j] = 0;
        }
       }
       return image;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the size of the image : ";
    cin >> n;

    vector<vector<int>> image(n, vector<int>(n));
    cout <<"Enter the elements of the image :"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> image[i][j];
        }
    }

    image = sol.flipAndInvertImage(image);
    cout <<"The flipped and inverted image is :"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << image[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}