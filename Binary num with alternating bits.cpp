
/* ================================== LeetCode version ======================================

- Time Complexity: O(1) 
- Space Complexity: O(1) 

class Solution {
public:
    bool hasAlternatingBits(int n) {
        /*
        -If a number has alternating bits (like 101010...), then shifting it right by 1 bit will create an opposite pattern.
        
        -When we XOR the number with that result and if it's perfectly alternating, the output will be a sequence of all 1s.

        -if it's a sequence of all 1s, adding 1 to them produces a power of two, and ANDing them will give 0.
        /

        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        /*
        -If a number has alternating bits (like 101010...), then shifting it right by 1 bit will create an opposite pattern.
        
        -When we XOR the number with that result and if it's perfectly alternating, the output will be a sequence of all 1s.

        -if it's a sequence of all 1s, adding 1 to them produces a power of two, and ANDing them will give 0.
        */

        unsigned int x = n ^ (n >> 1);
        return (x & (x + 1)) == 0;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter a positive integer : ";
    cin >> n;
    
    if(sol.hasAlternatingBits(n))
        cout <<"Has alternating bits." << endl;
    else
        cout <<"Does not have alternating bits." << endl;    

    return 0;
}