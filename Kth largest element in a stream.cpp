
/* ================================== LeetCode version ======================================

- Time Complexity: O(n log k) //For the constructor, O(log k) for each push/pop operation
- Space Complexity: O(k) //Because the heap stores at most k elements. 

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pri_q;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i = 0; i < nums.size(); i++){
            pri_q.push(nums[i]);
            if(pri_q.size() > k) pri_q.pop();
        }
    }
    
    int add(int val) {
        pri_q.push(val);
        if(pri_q.size() > size) pri_q.pop();

        return pri_q.top();
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pri_q;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i = 0; i < nums.size(); i++){
            pri_q.push(nums[i]);
            if(pri_q.size() > k) pri_q.pop();
        }
    }
    
    int add(int val) {
        pri_q.push(val);
        if(pri_q.size() > size) pri_q.pop();

        return pri_q.top();
    }
};

int main() {
    int k, n;

    cout <<"Enter k : ";
    cin >> k;

    cout <<"Enter number of initial elements : ";
    cin >> n;

    vector<int> nums(n);

    cout <<"Enter elements : ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    KthLargest sol(k, nums);

    int q;
    cout <<"How many values do you want to add? : ";
    cin >> q;

    cout <<"Enter values to add:\n";

    for (int i = 0; i < q; i++) {
        int val;
        cin >> val;

        cout <<"Kth largest = " << sol.add(val) << endl;
    }

    return 0;
}