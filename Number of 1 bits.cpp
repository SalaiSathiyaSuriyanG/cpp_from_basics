
/* ==================== LeetCode version =========================

- Time Complexity: O(k) //where k is the number of bits in the integer
- Space Complexity: O(1)

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter an unsigned integer: ";
    cin >> n;
    
    cout <<"The number of '1' bits in "<<n<<" is : "<<sol.hammingWeight(n);

    return 0;
}
