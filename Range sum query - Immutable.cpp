
/* ================================== LeetCode version ======================================

- Time Complexity: O(n + q) //Where n is the size of the input array and q is the number of queries.
- Space Complexity: O(n) //We create a prefix sum array of size n.
class NumArray {
private:
    vector<int> prefix;  //prefix[i] = sum of nums from [0 to i] 
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());

        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        //sum(left,right) = prefix[right] - prefix[left - 1]
        if(left == 0)
            return prefix[right];
        else
            return prefix[right] - prefix[left - 1];
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefix;  //prefix[i] = sum of nums from [0 to i] 
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());

        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        //sum(left,right) = prefix[right] - prefix[left - 1]
        if(left == 0)
            return prefix[right];
        else
            return prefix[right] - prefix[left - 1];
    }
};

int main(){
    int n,q;

    cout <<"Enter the number of elements in the array : ";
    cin >> n;

    vector<int> nums(n);
    cout <<"Enter the elements of the array : ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    NumArray sol(nums);

    cout <<"Enter the number of queries : ";
    cin >> q;

    for(int i = 0; i < q; i++){
        int left, right;
        cout <<"\nEnter the left and right indices for query "<< i + 1 << ": ";
        cin >> left >> right;

        cout <<"Sum = "<< sol.sumRange(left,right);
    }

    return 0;
}