
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n^3) 
- Space Complexity: O(1) 

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double Max = 0.0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; k++) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    
                    double area = 0.5 * (abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)));
                    Max = max(Max, area);
                }
            }
        }
        return Max;
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
    double largestTriangleArea(vector<vector<int>>& points) {
        double Max = 0.0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; k++) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    
                    double area = 0.5 * (abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)));
                    Max = max(Max, area);
                }
            }
        }
        return Max;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of points : ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    cout <<"Enter the points (x,y) : "<< endl;
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    cout <<"The largest triangle area is : "<< sol.largestTriangleArea(points)<< endl;
    
    return 0;
}