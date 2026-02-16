
/* ==================== LeetCode version =========================

- Time Complexity: O(m+n)
- Space Complexity: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

int main() {
    int m, n;

    cout<<"Enter the number of elements in nums1(m): ";
    cin>>m;

    cout<<"Enter the number of elements in nums2(n): ";
    cin>>n;
    
    vector<int> nums1(m + n);
    vector<int> nums2(n);

    cout<<"Enter "<<m<<" Sorted elements for nums1:\n";
    for(int i = 0; i < m; i++) {
        cin>>nums1[i];
    }

    cout<<"Enter "<<n<<" Sorted elements for nums2:\n";
    for(int i = 0; i < n; i++) {
        cin>>nums2[i];
    }

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout<<"Merged array:\n";
    for(int num : nums1) {
        cout<<num<<" ";
    }

    return 0;
}
