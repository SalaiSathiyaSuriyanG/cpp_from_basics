
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) //Where n is the number of elements in the array
- Space Complexity: O(1) 

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int n = arr.size() - 1;

        int i = 0;
        while(i < n && arr[i] < arr[i + 1]) i++;

        if(i == 0 || i == n) return false;

        while(i < n && arr[i] > arr[i + 1]) i++;

        return i == n;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        int n = arr.size() - 1;

        int i = 0;
        while(i < n && arr[i] < arr[i + 1]) i++;

        if(i == 0 || i == n) return false;

        while(i < n && arr[i] > arr[i + 1]) i++;

        return i == n;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);
    cout <<"Enter the elements of the array :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(sol.validMountainArray(arr))
        cout <<"\nIt is a valid mountain array." << endl;
    else
        cout <<"\nIt is not a valid mountain array." << endl;

    return 0;
}