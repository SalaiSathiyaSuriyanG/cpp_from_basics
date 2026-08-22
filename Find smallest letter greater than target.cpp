
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> freq(26, 0);
        for(char ch : letters){   
            freq[ch - 'a']++;
        }

        int t = target - 'a';  
        for(int i = t + 1; i < freq.size(); i++){
            if(freq[i] > 0)  
                return i + 'a';
        }
        return letters[0];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> freq(26, 0);
        for(char ch : letters){   
            freq[ch - 'a']++;
        }

        int t = target - 'a';  
        for(int i = t + 1; i < freq.size(); i++){
            if(freq[i] > 0)  
                return i + 'a';
        }
        return letters[0];
    }
};

int main(){
    Solution sol;
    int n;
    char target;
    cout <<"Enter the number of letters : ";
    cin >> n;

    vector<char> letters(n);
    cout <<"Enter the letters :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> letters[i];
    }

    cout <<"Enter the target letter : ";
    cin >> target;

    char result = sol.nextGreatestLetter(letters, target);
    cout <<"The smallest letter in the array that is greater than "<< target <<" is : "<< result;

    return 0;
}