
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            while(left < right && !isalpha(s[left])){
                left++;
            }

            while(left < right && !isalpha(s[right])){
                right--;
            }

            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            while(left < right && !isalpha(s[left])){
                left++;
            }

            while(left < right && !isalpha(s[right])){
                right--;
            }

            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    cin >> s;

    cout <<"Reversed string : "<< sol.reverseOnlyLetters(s) << endl;
    return 0;
}