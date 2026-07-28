
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0,y = 0;

        for(int m : moves){
            if(m == 'L') x--;
            else if(m == 'R') x++;
            else if(m == 'U') y++;
            else if(m == 'D') y--;
        }
        return x == 0 && y == 0;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0,y = 0;

        for(int m : moves){
            if(m == 'L') x--;
            else if(m == 'R') x++;
            else if(m == 'U') y++;
            else if(m == 'D') y--;
        }
        return x == 0 && y == 0;
    }
};

int main(){
    Solution sol;
    string A;
    
    cout <<"------ Left - L, Right - R, Up - U, Down - D ------"<< endl;
    cout <<"Enter the moves : ";
    cin >> A;

    cout <<"Does the Robot return to its origin ? : ";
    if(sol.judgeCircle(A))
        cout <<"Yes"<< endl;
    else
        cout <<"No"<< endl;  
        
    return 0;    
}