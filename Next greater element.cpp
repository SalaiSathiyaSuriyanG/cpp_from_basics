
/* ================================== LeetCode version ======================================

- Time Complexity: O(n + m) //n is the size of nums1 and m is the size of nums2.
- Space Complexity: O(n) 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nxtGreater;
        stack<int> st;

        //Iterate through nums2 to find the next greater element for each number.
        for(int num : nums2){
            while(!st.empty() && st.top() < num){
                nxtGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        //Assign -1 to any remaining elements in the stack.
        while(!st.empty()){
            nxtGreater[st.top()] = -1;
            st.pop();
        }

        //Push the next greater elements for nums1 into result.
        vector<int> result;
        for(int num : nums1){
            result.push_back(nxtGreater[num]);
        }
        return result;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nxtGreater;
        stack<int> st;

        //Iterate through nums2 to find the next greater element for each number.
        for(int num : nums2){ 
            while(!st.empty() && st.top() < num){
                nxtGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        //Assign -1 to any remaining elements in the stack.
        while(!st.empty()){
            nxtGreater[st.top()] = -1;
            st.pop();
        }

        //Push the next greater elements for nums1 into result.
        vector<int> result;
        for(int num : nums1){
            result.push_back(nxtGreater[num]);
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n,m;
    cout <<"Enter the number of elements in nums1 and nums2 : ";
    cin >> n >> m;

    vector<int> nums1(n),nums2(m);
    cout <<"Enter the elements of nums1 : ";
    for(int i=0; i<n; i++){
        cin >> nums1[i];
    }
    cout <<"Enter the elements of nums2 : ";
    for(int i=0; i<m; i++){
        cin >> nums2[i];
    }

    vector<int> result = sol.nextGreaterElement(nums1,nums2);
    cout <<"Next greater elements : [ ";
    for(int num : result){
        cout << num << " ";
    }
    cout <<"]"<< endl;

    return 0;
}