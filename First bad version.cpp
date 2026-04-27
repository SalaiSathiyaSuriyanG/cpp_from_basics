
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n) //Binary search
- Space Complexity: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid))
                right = mid;   
            else
                left = mid + 1;    
        }
        return right;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

int firstBad; //It stores the first version where things become bad

bool isBadVersion(int version){
    return version >= firstBad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid))
                right = mid;   
            else
                left = mid + 1;    
        }
        return right;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of versions : ";
    cin >> n;
    cout <<"Enter the first bad version : ";
    cin >> firstBad;

    int result = sol.firstBadVersion(n);
    cout <<"The first bad version is : " << result;

    return 0;
}