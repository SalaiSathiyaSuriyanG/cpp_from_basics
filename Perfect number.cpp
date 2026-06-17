
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 0) return false;

        int sum = 0;
        for(int i = 1; i < num; i++){
            if(num % i == 0)
                sum += i;
        }
        return sum == num;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 0) return false;

        int sum = 0;
        for(int i = 1; i < num; i++){
            if(num % i == 0)
                sum += i;
        }
        return sum == num;
    }
};

int main(){
    Solution sol;
    int num;
    cout <<"Enter an integer : ";
    cin >> num;
    if(sol.checkPerfectNumber(num))
        cout << "It is a perfect number.";
    else
        cout << "It is not a perfect number.";
    
    return 0;    
}