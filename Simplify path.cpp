
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(n) //In the worst case,stack stores all the directory names in the path.

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;
        string result;

        stringstream ss(path);  //Create a stream object named ss 

        while(getline(ss,curr,'/')){  //Read characters from ss until '/' is found and store the result in curr.
            if(curr == "" || curr == ".")
                continue;

            else if(curr == ".."){
                if(!stack.empty())
                    stack.pop_back();
            }    

            else
                stack.push_back(curr);
        }

        for(string direc : stack){
            result += "/" + direc;
        }

        return result.empty() ? "/" : result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;
        string result;

        stringstream ss(path);  //Create a stream object named ss 

        while(getline(ss,curr,'/')){  //Read characters from ss until '/' is found and store the result in curr.
            if(curr == "" || curr == ".")
                continue;

            else if(curr == ".."){
                if(!stack.empty())
                    stack.pop_back();
            }    

            else
                stack.push_back(curr);
        }

        for(string direc : stack){
            result += "/" + direc;
        }

        return result.empty() ? "/" : result;
    }
};

int main(){
    Solution sol;
    string path;
    cout <<"Enter the path : ";
    getline(cin,path);

    cout <<"Simplified path : "<< sol.simplifyPath(path);

    return 0;
}