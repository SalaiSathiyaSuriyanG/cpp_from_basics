
/* ================================== LeetCode Version ======================================

- Time Complexity: O(1) 
- Space Complexity: O(1) 

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && 
               rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[0] < rec2[2] && rec2[0] < rec1[2] && 
               rec1[1] < rec2[3] && rec2[1] < rec1[3];
    }
};

int main(){
    Solution sol;
    vector<int> rec1, rec2;

    cout <<"Enter the coordinates of the first rectangle (x1, y1, x2, y2): ";
    for(int i = 0; i < 4; i++){
        int coord;
        cin >> coord;
        rec1.push_back(coord);
    }
    
    cout <<"Enter the coordinates of the second rectangle (x1, y1, x2, y2): ";
    for(int i = 0; i < 4; i++){
        int coord;
        cin >> coord;
        rec2.push_back(coord); 
    }
    
    if(sol.isRectangleOverlap(rec1, rec2))
        cout <<"The rectangles overlap."<< endl;
    else 
        cout <<"The rectangles do not overlap."<< endl;
    
    return 0;    
}