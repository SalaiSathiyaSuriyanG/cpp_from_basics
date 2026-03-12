
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() -1;
        int maxArea = 0;
        while(left < right){
            int width = right - left;
            int container_h = min(height[left],height[right]);
            int area = width*container_h;

            maxArea = max(maxArea,area);
            if(height[left] < height[right])
                left++;
            else
                right--;    
        }
        return maxArea;
    }
};
=============================================================== */

// ==================== Runnable Version =========================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() -1;
        int maxArea = 0;
        while(left < right){
            int width = right - left;
            int container_h = min(height[left],height[right]);
            int area = width*container_h;

            maxArea = max(maxArea,area);
            if(height[left] < height[right])
                left++;
            else
                right--;    
        }
        return maxArea;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of  container heights : ";
    cin >>n;
    vector<int> height(n);
    cout <<"Enter the container heights : ";
    for(int i = 0; i < n; i++){
        cin >>height[i];
    }
    cout <<"The maximum area is : "<<sol.maxArea(height);

    return 0;
}