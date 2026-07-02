
/* ================================== LeetCode version ======================================

- Time Complexity: O(n log n) 
- Space Complexity: O(n) 

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        sort(candyType.begin(),candyType.end());
        int count = 1;

        for(int i = 1; i < n; i++){
            if(candyType[i] != candyType[i - 1]) 
                count++;
        }
        return (count > n/2) ? n/2 : count;
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
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        sort(candyType.begin(),candyType.end());
        int count = 1;

        for(int i = 1; i < n; i++){
            if(candyType[i] != candyType[i - 1]) 
                count++;
        }
        return (count > n/2) ? n/2 : count;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the no.of candies : ";
    cin >> n;

    vector<int>candyType(n);
    cout <<"Enter the types of candies : ";
    for(int i = 0; i < n; i++){
        cin >> candyType[i];
    }
    cout <<"Different types of candies that can be distributed are : "<< sol.distributeCandies(candyType);

    return 0;
}