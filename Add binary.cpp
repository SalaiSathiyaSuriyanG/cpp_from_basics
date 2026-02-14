
/* ==================== LeetCode version =========================

- Time Complexity: O(max(n,m))    // Time grows proportional to the length of the longer string
- Space Complexity: O(max(n,m))   // Space grows proportional to the length of the longer string

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        string result="";
        while(i>=0 || j>=0 || carry){
            int sum=carry;
            if(i>=0){
                sum += a[i]-'0';
                i--;
            }
            if(j>=0){
                sum += b[j]-'0';
                j--;
            }
            result += (sum % 2) +'0';
            carry=sum /2;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        string result="";
        while(i>=0 || j>=0 || carry){
            int sum=carry;
            if(i>=0){
                sum += a[i]-'0';
                i--;
            }
            if(j>=0){
                sum += b[j]-'0';
                j--;
            }
            result += (sum % 2) +'0';
            carry=sum /2;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main() {
	Solution sol;
    string a,b;
    
    cout<<"--------------BINARY ADDITION--------------";
    cout<<"\nEnter First binary string: ";
    cin>>a;

    cout<<"Enter Second binary string: ";
    cin>>b;
    
    string result = sol.addBinary(a,b);
    cout<<"Result: "<<result;

    return 0;
}
