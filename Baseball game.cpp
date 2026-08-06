
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;

        stack<int> st;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top1);
                st.push(top1 + top2);
            }

            else if(operations[i] == "C"){
                st.pop();
            }

            else if(operations[i] == "D"){
                st.push(st.top() * 2);
            }

            else{
                st.push(stoi(operations[i]));
            }
        }

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;

        stack<int> st;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.push(top1);
                st.push(top1 + top2);
            }

            else if(operations[i] == "C"){
                st.pop();
            }

            else if(operations[i] == "D"){
                st.push(st.top() * 2);
            }

            else{
                st.push(stoi(operations[i]));
            }
        }

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

int main(){
    Solution sol;
    int n;

    cout <<"You can enter the operations as follows :"<< endl;
    cout <<"\nEnter a number to record a new score."<< endl;
    cout <<"Enter '+' to record a new score that is the sum of the previous two scores."<< endl;
    cout <<"Enter 'D' to record a new score that is double the previous score."<< endl;
    cout <<"Enter 'C' to invalidate the previous score."<< endl;

    cout <<"\nEnter the number of operations : ";
    cin >> n;

    vector<string> operations(n);
    cout <<"Enter the operations : ";
    for(int i = 0; i < n; i++){
        cin >> operations[i];
    }

    cout <<"Total score is : "<< sol.calPoints(operations);

    return 0;
}