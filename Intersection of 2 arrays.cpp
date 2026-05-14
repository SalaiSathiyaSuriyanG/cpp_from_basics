
/* ================================== LeetCode version ======================================

- Time Complexity: O(n + m) //where n and m are the lengths of nums1 and nums2 respectively
- Space Complexity: O(n + m) //In the worst case, all the will be unique elements

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums(nums1.begin(),nums1.end());
        unordered_set<int> result;

        for(int num : nums2){
            if(nums.count(num)) 
                result.insert(num);
        }
        return vector<int> (result.begin(),result.end()); 
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums(nums1.begin(),nums1.end());
        unordered_set<int> result;

        for(int num : nums2){
            if(nums.count(num)) 
                result.insert(num);
        }
        return vector<int> (result.begin(),result.end()); 
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

    vector<int> result = sol.intersection(nums1,nums2);
    cout <<"Intersection of nums1 and nums2 is : ";
    for(int num : result){
        cout << num <<" ";
    }

    return 0;
}