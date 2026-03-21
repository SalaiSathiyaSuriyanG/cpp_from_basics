
/* ==================== LeetCode version =========================

- Time Complexity: O(log n) // The number of digits in n is log10(n).

- Space Complexity: O(log n) // Set stores intermediate values.
                                In practice, the number of values is very small,
                                so it behaves like O(1).

class Solution {
public:
int helper(int n){
        int sum = 0;
        while(n > 0){
            int a = n % 10;
            sum += a*a;
            n /= 10;
            }
            return sum;
        }
    
bool isHappy(int n) { 
       unordered_set<int> seen;
       while(n != 1 && !seen.count(n)){
        seen.insert(n);
        n = helper(n);
       }
       
       if(n == 1)
       return true;
       else
       return false;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
int helper(int n){
    int sum = 0;
    while(n > 0){
        int a = n % 10;
        sum += a*a;
        n /= 10;
        }
        return sum;
    }
    
bool isHappy(int n) { 
    unordered_set<int> seen;
    while(n != 1 && !seen.count(n)){
        seen.insert(n);
        n = helper(n);
    }
       
    if(n == 1)
    return true;
    else
    return false;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter an integer: ";
    cin >> n;
    cout <<sol.isHappy(n);
    
    return 0;
}