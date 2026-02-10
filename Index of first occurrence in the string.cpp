
/* ==================== LeetCode version =========================

- Time Complexity: O(n*m)
- Space Complexity: O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
        return 0;}
        int n=haystack.size();
        int m=needle.size();

        for(int i=0;i<=n-m;i++){
            int j=0;
            while(j<m && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==m)
            return i;
        }
        return -1;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
        return 0;
        }

        int n = haystack.size();
        int m = needle.size();

        for (int i=0;i<=n-m;i++) {
            int j=0;
            while (j<m && haystack[i + j] == needle[j]) {
            j++;
            }
            if (j == m) {
            return i;
            }
        }
        return -1;
    }
};

int main() {
    string haystack, needle;

    cout<<"Enter haystack string: ";
    getline(cin, haystack);

    cout<<"Enter needle string: ";
    getline(cin, needle);

    Solution obj;
    int result = obj.strStr(haystack, needle);

    if (result != -1) {
    cout<<"Needle found at index: " << result << endl;
    } 
	else {
    cout<<"Needle not found" << endl;
    }

    return 0;
}
