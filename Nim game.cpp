
/* ================================== LeetCode version ======================================

- Time Complexity: O(1)
- Space Complexity: O(1)

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
        //Multiples of 4 are trap states.Whoever faces them on their turn will lose if the opponent plays perfectly.
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
        //Multiples of 4 are trap states.Whoever faces them on their turn will lose if the opponent plays perfectly.
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    if(sol.canWinNim(n))
        cout <<"You can win the game!"<< endl;
    else
        cout <<"You can't win the game"<< endl;

    return 0;
}
