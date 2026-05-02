
/* ================================== LeetCode version ======================================

- Time Complexity:  O(n log n)  //Sorting takes O(n log n) and merging takes O(n) -> O(n log n) + O(n) = O(n log n) sorting dominates.
- Space Complexity: O(n)  //In the worst case we store all the intervals

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> result;

        for(auto& interval : intervals){ 
            //if the result is empty or if the previous interval's end is < current interval's start
            if(result.empty() || result.back()[1] < interval[0])
                result.push_back(interval);
            /* back() gives the last interval of result.
               Each interval is a vector holding [start,end]
               [0] is the start and [1] is the end of an interval /

            else
                result.back()[1] = max(result.back()[1],interval[1]);    
        }
        return result;
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> result;

        for(auto& interval : intervals){ 
            //if the result is empty or if the previous interval's end is < current interval's start
            if(result.empty() || result.back()[1] < interval[0])
                result.push_back(interval);
            /* back() gives the last interval of result.
               Each interval is a vector holding [start,end]
               [0] is the start and [1] is the end of an interval */

            else
                result.back()[1] = max(result.back()[1],interval[1]);    
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of intervals : ";
    cin >> n;

    vector<vector<int>> intervals(n,vector<int>(2));
    cout <<"Enter the intervals (start and end) : ";
    for(int i = 0; i < n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    
    vector<int> newInterval(2);
    cout <<"Enter the new interval (start and end) : ";
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> insertedIntervals = sol.insert(intervals,newInterval);
    cout <<"New intervals : ";
    for(const auto& interval : insertedIntervals){
        cout <<" ["<< interval[0] <<","<< interval[1] <<"] ";
    }
    cout <<endl;

    return 0;
}