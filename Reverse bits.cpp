
/* ==================== LeetCode version =========================

- Time Complexity: O(1) // Because the loop runs exactly 32 times,which is a constant.
- Space Complexity: O(1)

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i<32; i++){
            result <<= 1;  //shifts every bit to the left side by 1
            result |= (n & 1); //inserts one bit to the rightmost position 
            n >>= 1;  //shifts all the bits to the right, removing the last bit and bringing the next bit into position
        }
        return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <cstdint>  //For fixed-size integers
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i<32; i++){
            result <<= 1;  //shifts every bit to the left side by 1
            result |= (n & 1); //inserts one bit to the rightmost position 
            n >>= 1;  //shifts all the bits to the right, removing the last bit and bringing the next bit into position
        }
        return result;
    }
};

int main(){
    Solution sol;
    uint32_t n;
    cout <<"Enter an integer : ";
    cin >> n;
    uint32_t reversed = sol.reverseBits(n);
    cout <<"Integer equivalent after reversing the bits : "<<sol.reverseBits(n);

    return 0;
}