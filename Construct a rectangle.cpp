
/* ================================== LeetCode version ======================================

- Time Complexity: O(√n) //Where n is the input area. 
- Space Complexity: O(1) 

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int len = area;
        int wid = 1;
        //We initialize len = area and wid = 1,so that even if we never find any better factor pair,we already have a valid answer stored.(area,1) is a valid rectangle.

        for(int w = 1; w*w <= area; w++){
            if(area % w == 0){  //We check whether w is a factor of area because,whenever it's a factor we can form a rectangle.
                wid = w;
                len = area / w;
            }
        }
        //As w increases toward √area,the factors become closer and closer.
        return {len,wid};
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int len = area;
        int wid = 1;
        //We initialize len = area and wid = 1,so that even if we never find any better factor pair,we already have a valid answer stored.(area,1) is a valid rectangle.

        for(int w = 1; w*w <= area; w++){
            if(area % w == 0){  //We check whether w is a factor of area because,whenever it's a factor we can form a rectangle.
                wid = w;
                len = area / w;
            }
        }
        //As w increases toward √area,the factors become closer and closer.
        return {len,wid};
    }
};

int main(){
    Solution sol;
    int area;
    cout <<"Enter the area of the rectangle : ";
    cin >> area;

    vector<int> result = sol.constructRectangle(area);
    cout <<"The length and width of the rectangle are : ";
    cout <<"{"<<result[0] <<","<< result[1] <<"}"<< endl;

    return 0;
}                                      