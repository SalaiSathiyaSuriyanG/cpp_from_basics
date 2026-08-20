
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> arr;

        for(int i = left; i <= right; i++){
            bool valid = true;
            int n = i;

            while(n != 0){
                int rem = n % 10;
                if(rem == 0 || i % rem != 0){
                    valid = false;
                    break;
                }
                n /= 10; 
            }
            if(valid == true)
               arr.push_back(i);
        }
        return arr;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> arr;

        for(int i = left; i <= right; i++){
            bool valid = true;
            int n = i;

            while(n != 0){
                int rem = n % 10;
                if(rem == 0 || i % rem != 0){
                    valid = false;
                    break;
                }
                n /= 10; 
            }
            if(valid == true)
               arr.push_back(i);
        }
        return arr;
    }
};

int main(){
    Solution sol;
    int left, right;
    cout <<"Constraint : 1 <= left <= right <= 10000"<< endl;
    cout <<"\nEnter the range (left and right) : "<< endl;
    cin >> left >> right;

    vector<int> result = sol.selfDividingNumbers(left, right);
    cout <<"\nSelf-Dividing Numbers in the given range are : "<< endl;
    for(int num : result){
        cout << num <<"  ";
    }

    return 0;
} 