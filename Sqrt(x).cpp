
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int mySqrt(int x) {
        int left=1;
        int right=x;
        if(x==0)
        return 0;

        while(left<=right){

            int mid =left + (right-left)/2;
            if(mid == x/mid)
            return mid;

            if(mid <= x/mid){
            left=mid+1;
            }
            else{
            right=mid-1;
            }
        }
        return right;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left=1;
        int right=x;
        if(x==0)
        return 0;

        while(left<=right){

            int mid =left + (right-left)/2;
            if(mid == x/mid)
            return mid;

            if(mid <= x/mid){
            left=mid+1;
            }
            else{
            right=mid-1;
            }
        }
        return right;
    }
};

int main() {
	Solution sol;
    int x;

    cout<<"Enter a non-negative integer: ";
    cin>>x;

    int result = sol.mySqrt(x);
    cout<<"Square root: " << result;

    return 0;
}
