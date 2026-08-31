
/* ================================== LeetCode Version ======================================

- Time Complexity: O(D*(sqrt(log n))) //Where D is the diff btw right and left
- Space Complexity: O(1) 

class Solution {
private:
bool isPrime(int n){
    if(n <= 1) return false;

    for(int i = 2; i*i <= n; i++){
        //Return false if more than 2 factors are found
        if(n % i == 0) return false;
    }
    return true;
}

public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;

        while(left <= right){
            int setBits = __builtin_popcount(left); //Built in function to find the count of set bits
            if(isPrime(setBits)){
                count++;
            }
            left++;
        }
        return count;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
using namespace std;

class Solution {
private:
bool isPrime(int n){
    if(n <= 1) return false;

    for(int i = 2; i*i <= n; i++){
        //Return false if more than 2 factors are found
        if(n % i == 0) return false;
    }
    return true;
}

public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;

        while(left <= right){
            int setBits = __builtin_popcount(left); //Built in function to find the count of set bits
            if(isPrime(setBits)){
                count++;
            }
            left++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    int left,right;
    cout <<"Enter the range (left and right) : ";
    cin >> left >> right;

    cout <<"Count of prime number of set bits is : "<< sol.countPrimeSetBits(left, right)<< endl;

    return 0;
}