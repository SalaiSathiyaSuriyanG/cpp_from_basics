
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) //Where n is the length of the typed string
- Space Complexity: O(1) 

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        int i = 0,j = 0;

        while(j < n){
            // If we haven't reached the end of name, and the current characters are identical, match found!
            if(i < m && name[i] == typed[j]){
                i++;
                j++;
            }

            // If it's not the first character AND the current character matches the previous one, it's a "long press"
            else if(j > 0 && typed[j] == typed[j - 1]) j++;
            
            // If the characters don't match and it's not a long press, it's an error
            else return false;
        }
        return i == m;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        int i = 0,j = 0;

        while(j < n){
            // If we haven't reached the end of name, and the current characters are identical, match found!
            if(i < m && name[i] == typed[j]){
                i++;
                j++;
            }

            // If it's not the first character AND the current character matches the previous one, it's a "long press"
            else if(j > 0 && typed[j] == typed[j - 1]) j++;
            
            // If the characters don't match and it's not a long press, it's an error
            else return false;
        }
        return i == m;
    }
};

int main(){
    Solution sol;
    string n, t;

    cout <<"Enter a name : ";
    cin >> n;
    cout <<"Enter the typed string : ";
    cin >> t;

    cout <<"\nIs the typed string a long pressed version of the name? : " 
         << (sol.isLongPressedName(n, t) ? "Yes" : "No") << endl;

    return 0;     
}