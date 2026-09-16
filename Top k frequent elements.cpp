
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n log n) 
    //Because we are using a priority queue to sort the frequencies, 
    //which takes O(log n) time for each insertion. 
    //In the worst case, we may have to insert all n elements into the priority queue. 

- Space Complexity: O(n) 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it : freq){
            pq.push({it.second, it.first});
            //This forces the Max-Heap to sort everything by frequency 
            //placing the most frequent numbers right at the top
        }

        while(k > 0){
            result.push_back(pq.top().second);
            //Here,  .second gives the actual number
            pq.pop();
            k--;
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it : freq){
            pq.push({it.second, it.first});
            //This forces the Max-Heap to sort everything by frequency 
            //placing the most frequent numbers right at the top
        }

        while(k > 0){
            result.push_back(pq.top().second);
            //Here,  .second gives the actual number
            pq.pop();
            k--;
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n, k;
    cout <<"Enter the size of the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array : "<< endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout <<"\nEnter the number of top frequent elements you want : ";
    cin >> k;

    cout <<"\nThe top "<< k <<" frequent elements are : ";
    vector<int> result = sol.topKFrequent(nums, k);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    return 0;
}