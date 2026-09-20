
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_dol = 0;
        int ten_dol = 0;

        for(int x : bills){
            if(x == 5) five_dol++;

            else if(x == 10){
                if(five_dol > 0){
                    five_dol--;
                    ten_dol++;
                } 
                else return false;
            }
            
            else{
                if(five_dol > 0 && ten_dol > 0){
                    five_dol--;
                    ten_dol--;
                }
                else if(five_dol > 2) five_dol -= 3;

                else return false;
            }
        }
        return true;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_dol = 0;
        int ten_dol = 0;

        for(int x : bills){
            if(x == 5) five_dol++;

            else if(x == 10){
                if(five_dol > 0){
                    five_dol--;
                    ten_dol++;
                } 
                else return false;
            }
            
            else{
                if(five_dol > 0 && ten_dol > 0){
                    five_dol--;
                    ten_dol--;
                }
                else if(five_dol > 2) five_dol -= 3;

                else return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of bills : ";
    cin >> n;

    vector<int> bills(n);
    cout <<"Enter the bills (5, 10, or 20) : ";
    for(int i = 0; i < n; i++){
        cin >> bills[i];
    }

    cout <<"Can we provide change for all customers? : " << (sol.lemonadeChange(bills) ? "Yes" : "No") << endl;

    return 0;
}