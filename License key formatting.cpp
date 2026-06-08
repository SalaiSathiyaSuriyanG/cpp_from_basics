
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) //n is the length of the string s.
- Space Complexity: O(1) //We're creating a new string that stores almost all the characters from the input plus some dashes.So extra memory grows linearly with input size:

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result;
        int count = 0;

        for(int i = s.size() - 1; i >= 0; i--){ //We build from end as building from front is a lot of work than from end.
            if(s[i] == '-') continue;  //First,skip all the dashes

            if(count == k){  
                result.push_back('-');
                count = 0;
            }
            result.push_back(toupper(s[i]));
            count++;
        }
        //Since we do from the end,the result will be in reverse order. So,
        reverse(result.begin(),result.end());  
        return result;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result;
        int count = 0;

        for(int i = s.size() - 1; i >= 0; i--){ //We build from end as building from front is a lot of work than from end.
            if(s[i] == '-') continue;  //First,skip all the dashes

            if(count == k){  
                result.push_back('-');
                count = 0;
            }
            result.push_back(toupper(s[i]));
            count++;
        }
        //Since we do from the end,the result will be in reverse order. So,
        reverse(result.begin(),result.end());  
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    int k;
    cout <<"Enter the License Key string : ";
    cin >> s;
    cout <<"Enter the size of each group : ";
    cin >> k;

    cout <<"Formatted License Key : "<< sol.licenseKeyFormatting(s, k);
    
    return 0;
}