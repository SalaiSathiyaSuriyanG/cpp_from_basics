
/* ================================== LeetCode version ======================================

- Time Complexity: O(n + m) //where n and m are the lengths of nums1 and nums2 respectively
- Space Complexity: O(n) //Worst case, all elements in nums1 are unique 

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> result;

        for(int num : nums1){  //Create and assign Key->Frequency pair
            freq[num]++;
        }
        for(int num : nums2){
            if(freq[num] > 0){  //Check if the num is already in nums1 
                result.push_back(num);
                freq[num]--;
            }
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> result;

        for(int num : nums1){  //Create and assign Key->Frequency pair
            freq[num]++;
        }
        for(int num : nums2){
            if(freq[num] > 0){  //Check if the num is already in nums1 
                result.push_back(num);
                freq[num]--;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n,m;
    cout <<"Enter the number of elements in nums1 and nums2 : ";
    cin >> n >> m;

    vector<int> nums1,nums2;
    cout <<"Enter the elements of nums1 : ";
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums1.push_back(num);
    }

    cout <<"Enter the elements of nums2 : ";
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        nums2.push_back(num);
    }

    vector<int> result = sol.intersect(nums1,nums2);
    cout <<"Intersection of nums1 and nums2 is : [ ";
    for(int num : result){
        cout << num <<" ";
    }
    cout <<"]";

    return 0;
}