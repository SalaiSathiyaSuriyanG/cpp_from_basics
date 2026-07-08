
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;

        for(int  i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)){

                flowerbed[i] = 1;
                n--;
                if(n == 0) return true;
            }    
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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;

        for(int  i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)){

                flowerbed[i] = 1;
                n--;
                if(n == 0) return true;
            }    
        }
        return false;
    }
};

int main(){
    Solution sol;
    int m,n;
    cout <<"Enter the size of flowerbed : ";
    cin >> m;

    vector<int> flowerbed(m);

    cout <<"Enter the flowerbed elements (0 or 1) : ";
    for(int i = 0; i < m; i++){
        cin >> flowerbed[i];
    }

    cout <<"Enter the number of flowers to plant : ";
    cin >> n;

    cout <<"Possible to place the new flowers? : "<< (sol.canPlaceFlowers(flowerbed,n) ? "Yes" : "No");

    return 0;
}