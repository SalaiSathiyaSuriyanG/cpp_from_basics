
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0,length = 0;
        for(int right = 0;right<s.size();right++){
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            length = max(length,right-left+1);
        }
        return length; 
    }    
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0,length = 0;
        for(int right = 0;right<s.size();right++){
            while(seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            length = max(length,right-left+1);
        }
        return length; 
    }    
};

int main(){
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without duplicates : " << result;
    return 0;
}