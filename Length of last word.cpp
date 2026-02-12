
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        int length=0;

        while(i>=0 && s[i]==' '){
        i--;
        }
        while(i>=0 && s[i]!=' '){
            length++;
            i--;
        }
        return length;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        int length = 0;

        while(i>=0 && s[i]==' ') {
            i--;
        }
        while(i>=0 && s[i]!=' ') {
            length++;
            i--;
        }
        return length;
    }
};

int main() {
    string s;
    cout<<"Enter a sentence or a word : ";
    getline(cin, s);

    Solution obj;
    cout<<"Length of the Last word : ";
    cout<<obj.lengthOfLastWord(s);
    return 0;
}
