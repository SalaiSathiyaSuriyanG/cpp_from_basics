
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n) //Binary search
- Space Complexity: O(1)

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1)
            return true;

        long long left = 1;
        long long right = num;

        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long sqar = mid * mid;

            if(sqar == num)
                return true;
            else if(sqar < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1)
            return true;

        long long left = 1;
        long long right = num;

        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long sqar = mid * mid;

            if(sqar == num)
                return true;
            else if(sqar < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int main(){
    Solution sol;
    int num;
    cout <<"Enter an integer : ";
    cin >> num;

    if(sol.isPerfectSquare(num))
    cout << num <<" is a perfect square.";
    else
    cout << num <<" is not a perfect square.";

    return 0;
}