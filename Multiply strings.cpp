
/* ================================== LeetCode version ======================================

- Time Complexity: O(n * m) // where n and m are the lengths of num1 and num2 respectively
- Space Complexity: O(n + m) //In the worst case, the result can have at most n + m digits

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);
        string answer = "";

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >=0; j--){
                int digit1 = num1[i] - '0'; 
                int digit2 = num2[j] - '0';

                int prod = digit1 * digit2;
                int sum = prod + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        for(int num : result){
            if(!(answer.empty() && num == 0)){
                answer += (num + '0');
            }
        }
        return answer.empty() ? "0" : answer;
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
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);
        string answer = "";

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >=0; j--){
                int digit1 = num1[i] - '0'; 
                int digit2 = num2[j] - '0';

                int prod = digit1 * digit2;
                int sum = prod + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        for(int num : result){
            if(!(answer.empty() && num == 0)){
                answer += (num + '0');
            }
        }
        return answer.empty() ? "0" : answer;
    }
};

int main(){
    Solution sol;
    string a,b;
    cout <<"Enter two integers : ";
    cin >>a>>b;
    cout <<"The product of "<<a<<" and "<<b<<" is : "<<sol.multiply(a,b);

    return 0;
}