
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n) 
- Space Complexity: O(1) 

class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int temp = num;

        while(temp){
            result = (result << 1) | 1;  //Left shift the result by 1 bit and set the rightmost bit to 1 
            temp >>= 1; //Right shift temp each time by 1 bit,until no bit reamins
        }
        return result ^ num;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int temp = num;

        while(temp){
            result = (result << 1) | 1;  //Left shift the result by 1 bit and set the rightmost bit to 1 
            temp >>= 1; //Right shift temp each time by 1 bit,until no bit reamins
        }
        return result ^ num;
    }
};

int main(){
    Solution sol;
    int num;
    cout <<"Enter an integer : ";
    cin >> num;
    cout <<"The complement of "<< num <<" is : "<< sol.findComplement(num);

    return 0;
}