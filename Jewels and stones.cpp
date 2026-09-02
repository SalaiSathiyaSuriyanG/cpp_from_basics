
/* ================================== LeetCode Version ======================================

- Time Complexity: O(m*n) 
- Space Complexity: O(1) 

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int num = 0;
        for(char ch : jewels){
            num += count(stones.begin(), stones.end(), ch);
        }
        return num;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int num = 0;
        for(char ch : jewels){
            num += count(stones.begin(), stones.end(), ch);
        }
        return num;
    }
};

int main(){
    Solution sol;
    string j,s;

    cout <<"Enter the jewels : ";
    cin >> j;
    
    cout <<"Enter the stones : ";
    cin >> s;
    
    cout <<"Number of jewels in stones : " << sol.numJewelsInStones(j, s) << endl;

    return 0;
}