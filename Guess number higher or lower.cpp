
/* ================================== LeetCode version ======================================

- Time Complexity: O(log n)
- Space Complexity: O(1)

/
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);


class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int result = guess(mid);

            if(result == 0)
                return mid;
            else if(result == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

int pick;

int guess(int num){
    if(num == pick) 
        return 0;
    else if(num < pick)
        return 1;
    else 
        return -1;    
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int result = guess(mid);

            if(result == 0)
                return mid;
            else if(result == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    int n,UserGuess;

    cout <<"Enter the range : ";
    cin >> n;
    cout <<"Enter the picked number : ";
    cin >> pick;
    cout <<"Enter your guess : ";
    cin >> UserGuess;

    cout << endl;
    int result = guess(UserGuess);

    if(result == 0)
        cout <<"\nThat's Correct!!";
    else if(result == 1)
        cout <<"\nIt's Higher than that.";
    else
        cout <<"\nIt's Lower than that.";

    cout << endl;    
    cout <<"\nThe picked number is : "<< sol.guessNumber(n);

    return 0;
}