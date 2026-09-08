
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) //Where n is the length of the string s.
- Space Complexity: O(1) 

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> result(2,0);
        if(s.size() == 0) return result;

        int sum = 0;
        //result[0] is the total number of lines.
        result[0] = 1; 

        for(int i = 0; i < s.size(); i++){
            int temp = widths[s[i] - 'a']; 

            if(sum + temp <= 100){
                sum += temp;               
            }
            else{
                result[0]++;
                sum = temp;
            }
        }
        //result[1] is the width of the last line in pixels.
        result[1] = sum;

        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> result(2,0);
        if(s.size() == 0) return result;

        int sum = 0;
        //result[0] is the total number of lines.
        result[0] = 1; 

        for(int i = 0; i < s.size(); i++){
            int temp = widths[s[i] - 'a']; 

            if(sum + temp <= 100){
                sum += temp;               
            }
            else{
                result[0]++;
                sum = temp;
            }
        }
        //result[1] is the width of the last line in pixels.
        result[1] = sum;

        return result;
    }
};

int main(){
    Solution sol;
    string s;
    cout <<"Enter a string : ";
    cin >> s;

    vector<int> widths(26);
    cout <<"\nEnter the widths of each character (26 integers) :"<< endl;
    for(int i = 0; i < 26; i++){
        cin >> widths[i];
    }

    vector<int> result = sol.numberOfLines(widths, s);
    cout <<"\nNumber of lines: " << result[0] << endl;
    cout <<"Width of the last line: " << result[1] << endl;

    return 0;
}