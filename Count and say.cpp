
/* ==================== LeetCode version =========================

- Time Complexity: O(2^n)
- Space Complexity: O(2^n)
  /*The string keeps growing(approximately O(2^n)), and we process the whole string every time.
    So both time and space grow exponentially./

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for(int i = 1; i<n; i++){  //we start from 1 because we already have the first term of the sequence.
            string temp = "";
            int count = 1;

            for(int j = 1; j<result.size(); j++){  //we start from 1 because we will compare it with the previous string character.
                if(result[j] == result[j - 1])
                    count++;
                else{
                    temp += to_string(count);
                    temp += result[j - 1];
                    count = 1;
                }
            }
            temp += to_string(count);
            temp += result.back();
            result = temp;
        }
        return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for(int i = 1; i<n; i++){  //we start from 1 because we already have the first term of the sequence.
            string temp = "";
            int count = 1;

            for(int j = 1; j<result.size(); j++){  //we start from 1 because we will compare it with the previous string character.
                if(result[j] == result[j - 1])
                    count++;
                else{
                    temp += to_string(count);
                    temp += result[j - 1];
                    count = 1;
                }
            }
            temp += to_string(count);
            temp += result.back();
            result = temp;
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter which term of the sequence you want : ";
    cin >> n;
    cout <<"The sequence is : "<<sol.countAndSay(n);

    return 0;
}