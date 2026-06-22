
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        
        for(int i = 0; i < n; i += 2*k){
            int left = i;
            int right = min(i + k - 1,n - 1);

            while(left < right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
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
    string reverseStr(string s, int k) {
        int n = s.size();
        
        for(int i = 0; i < n; i += 2*k){ 
            int left = i;
            int right = min(i + k - 1,n - 1);

            while(left < right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s;
    int k;
    
    cout <<"Enter the string : ";
    cin >> s;
    cout <<"Enter the no.of characters to reverse : ";
    cin >> k;

    cout <<"Reversed string : "<<sol.reverseStr(s,k);

    return 0;
}