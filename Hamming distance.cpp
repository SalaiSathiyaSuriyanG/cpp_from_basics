
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) //Where n is the no.of bits
- Space Complexity: O(1) 

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int A = x ^ y;

        while(A){
            count += A & 1;
            A >>= 1;
        }
        return count;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int A = x ^ y; 

        while(A){
            count += A & 1; //If the LSB is 1,increment count 
            A >>= 1;  //Move to next bit
        }
        return count;
    }
};

int main(){
    Solution sol;
    int x,y;
    cout <<"Enter two integers : ";
    cin >>x >>y;
    cout <<"Hamming distance is : "<<sol.hammingDistance(x,y);

    return 0;
}    