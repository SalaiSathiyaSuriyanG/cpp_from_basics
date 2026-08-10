
/* ================================== LeetCode version ======================================

- Time Complexity: O(n log n) 
- Space Complexity: O(1) 

class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
        //vector[0] represents the start time of an interval.
        //vector[1] represents the end time of an interval.
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        //Including comparator here, makes the compiler to use your logic of sorting instead of sorting in ascending order.

        int n = intervals.size();
        int prev = 0, count = 1;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
                count++;
            }
        }
        return n - count;
    }
}; 
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
        //vector[0] represents the start time of an interval.
        //vector[1] represents the end time of an interval.
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        //Including comparator here, makes the compiler to use your logic of sorting instead of sorting in ascending order.

        int n = intervals.size();
        int prev = 0, count = 1;
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
                count++;
            }
        }
        return n - count;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of intervals : ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    cout <<"Enter the intervals (start and end times) : " << endl;
    for(int i = 0; i < n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    
    cout << "Minimum intervals to remove : " << sol.eraseOverlapIntervals(intervals);

    return 0;
}