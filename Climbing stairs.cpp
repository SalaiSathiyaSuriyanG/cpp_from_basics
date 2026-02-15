
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
        return 1;

        if(n<=2)
        return n;
        vector<int> ways(n+1);
        ways[1]=1;
        ways[2]=2;
        for(int i=3;i<=n;i++){
            ways[i]=ways[i-1]+ways[i-2]; 
        }
        return ways[n];
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
        return 1;

        if(n<=2)
        return n;
        vector<int> ways(n+1);
        ways[1]=1;
        ways[2]=2;
        for(int i=3;i<=n;i++){
            ways[i]=ways[i-1]+ways[i-2]; 
        }
        return ways[n];
    }
};

int main(){
	Solution sol;
	int n;
	cout<<"Enter the step you want to reach : ";
	cin>>n;
	cout<<"No.of ways to reach step "<<n<<" : "<<sol.climbStairs(n);
}