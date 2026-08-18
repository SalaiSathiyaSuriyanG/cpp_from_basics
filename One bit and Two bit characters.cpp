
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        for(; i < n-1; i++){
            if(bits[i] == 1) i++;
        }
        return i == n-1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        for(; i < n-1; i++){
            if(bits[i] == 1) i++;
        }
        return i == n-1;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of bits : ";
    cin >> n;

    vector<int> bits(n);
    cout <<"Enter the bits :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> bits[i];
    }

    if(sol.isOneBitCharacter(bits)) 
        cout <<"It's a one-bit character"<< endl;
    else 
        cout <<"It's not a one-bit character"<< endl;

    return 0;    
}