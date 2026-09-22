
/* ================================== LeetCode Version ======================================

- Time Complexity: O(log n) //Because we are iterating through the bits of the number, 
                            //which is logarithmic in relation to the value of n. 
- Space Complexity: O(1) 

class Solution {
public:
    int binaryGap(unsigned n) {
        // dist: Tracks the maximum gap found so far
        // pos: Tracks the previous position (32 is a dummy starting number)
        int dist = 0, pos = 32;

        // Keep looping as long as there are '1' bits left in the number
        while (n > 0) {
            // Find the index of the current rightmost '1' bit
            // __builtin_ctz is an automatic compiler shortcut for counting trailing zeros
            int count_trailing_zeros = __builtin_ctz(n);

            // Measure the distance from the previous position and make it as our new record
            dist = max(dist, count_trailing_zeros - pos);
            
            // Move our position forward to where we are standing right now
            pos = count_trailing_zeros;

            // Pop the rightmost '1' bit so we can look for the next one
            n &= (n - 1);
        }
        return dist;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <bit>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binaryGap(unsigned n) {
        // dist: Tracks the maximum gap found so far
        // pos: Tracks the previous position (32 is a dummy starting number)
        int dist = 0, pos = 32;

        // Keep looping as long as there are '1' bits left in the number
        while (n > 0) {
            // Find the index of the current rightmost '1' bit
            // __builtin_ctz is an automatic compiler shortcut for counting trailing zeros
            int count_trailing_zeros = __builtin_ctz(n);

            // Measure the distance from the previous position and make it as our new record
            dist = max(dist, count_trailing_zeros - pos);
            
            // Move our position forward to where we are standing right now
            pos = count_trailing_zeros;

            // Pop the rightmost '1' bit so we can look for the next one
            n &= (n - 1);
        }
        return dist;
    }
};

int main(){
    Solution sol;
    unsigned n;
    cout <<"Enter a positive integer : ";
    cin >> n;
    
    cout <<"The maximum binary gap is : " << sol.binaryGap(n) << endl;

    return 0;
}