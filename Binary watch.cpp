
/* ================================== LeetCode version ======================================

- Time Complexity: O(1) // The number of possible times on a binary watch is constant (12 hours * 60 minutes = 720 combinations).
- Space Complexity: O(k) // Where k is the number of valid times stored in result,which is at most 720.

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int hr = 0; hr < 12; hr++){
            for(int min = 0; min < 60; min ++){
                if(__builtin_popcount(hr) + __builtin_popcount(min) == turnedOn){
                    /*__builtin_popcount() is a GCC/Clang built-in function in C++ that counts the number of 
                    set bits 1's in the binary representation of an integer.*
                    string time = to_string(hr) + ":";

                    if(min < 10)
                        time += "0";

                    time += to_string(min);
                    result.push_back(time);    
                }
            }
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for(int hr = 0; hr < 12; hr++){
            for(int min = 0; min < 60; min ++){
                if(__builtin_popcount(hr) + __builtin_popcount(min) == turnedOn){
                    /*__builtin_popcount() is a GCC/Clang built-in function in C++ that counts the number of 
                    set bits 1's in the binary representation of an integer.*/
                    string time = to_string(hr) + ":";

                    if(min < 10)
                        time += "0";

                    time += to_string(min);
                    result.push_back(time);    
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int turnedOn;
    cout <<"Enter the number of LEDs that are currently ON : "; 
    cin >> turnedOn;

    vector<string> times = sol.readBinaryWatch(turnedOn);
    cout <<"Possible times the binary watch can represent with " << turnedOn << " LEDs ON : ";
    for(const string& time : times){
        cout <<"["<< time <<"] ";
    }
    cout << endl;

    return 0;
}