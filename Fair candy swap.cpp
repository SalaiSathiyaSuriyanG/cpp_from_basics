
/* ================================== LeetCode Version ======================================

- Time Complexity: O(m + n) //Where m is the no.of candies Alice has and n is the no.of candies Bob has.
- Space Complexity: O(n) //We are using a hashset to store Bob's candies.

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = 0, sum2 = 0;

        for(int A : aliceSizes) sum1 += A;
        for(int B : bobSizes) sum2 += B;

        int diff = (sum2 - sum1) / 2;

        unordered_set<int> bob(bobSizes.begin(), bobSizes.end());

        for(int a : aliceSizes){
            // Look through each of Alice's candies to find a fair trade.
            // For each candy 'a' Alice gives away, she needs a candy from Bob that is exactly 'a + diff'.
            // If Bob has it, we found our pair and return the result immediately.
            if(bob.count(a + diff)) return {a, a + diff};
        }
        return {};
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = 0, sum2 = 0;

        for(int A : aliceSizes) sum1 += A;
        for(int B : bobSizes) sum2 += B;

        int diff = (sum2 - sum1) / 2;

        unordered_set<int> bob(bobSizes.begin(), bobSizes.end());

        for(int a : aliceSizes){
            // Look through each of Alice's candies to find a fair trade.
            // For each candy 'a' Alice gives away, she needs a candy from Bob that is exactly 'a + diff'.
            // If Bob has it, we found our pair and return the result immediately.
            if(bob.count(a + diff)) return {a, a + diff};
        }
        return {};
    }
};

int main(){
    Solution sol;
    int m,n;

    cout <<"Enter the number of candies Alice has : ";
    cin >> m;
    cout <<"Enter the number of candies Bob has : ";
    cin >> n;

    vector<int> aliceSizes(m), bobSizes(n);

    cout <<"\nEnter the sizes of candies Alice has :"<< endl;
    for(int i = 0; i < m; i++) 
        cin >> aliceSizes[i];

    cout <<"\nEnter the sizes of candies Bob has :"<< endl;
    for(int i = 0; i < n; i++) 
        cin >> bobSizes[i];
    
    vector<int> result = sol.fairCandySwap(aliceSizes, bobSizes);
    
    if(!result.empty())
        cout <<"\nAlice should give away candy of size "<< result[0] 
             <<" and Bob should give away candy of size "<< result[1] << endl;
    else
        cout <<"\nNo fair trade possible." << endl;   
        
    return 0;    
}