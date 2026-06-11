
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int total = 0;

        if(n == 0)
            return 0;

        /*If gap < duration,
            Previous poison is still active.
            Only 'gap' seconds are newly added.

          If gap >= duration,
            Previous poison has already ended.
            Current attack contributes its full duration./  

        for(int i = 1; i < n; i++){
            int gap = timeSeries[i] - timeSeries[i - 1];
            total += min(gap,duration);  
        }    

        /* The loop counts contributions up to the next attack.
           The last attack has no next attack,so it always contributes its full duration./
        total += duration;
        return total;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int total = 0;

        if(n == 0)
            return 0;

        /*If gap < duration,
            Previous poison is still active.
            So,only 'gap' seconds are newly added.

          If gap >= duration,
            Previous poison has already ended.
            So,current attack contributes its full duration.*/  

        for(int i = 1; i < n; i++){
            int gap = timeSeries[i] - timeSeries[i - 1];
            total += min(gap,duration);  
        } 

        /* The loop counts contributions up to the next attack.
           The last attack has no next attack,so it always contributes its full duration.*/
        total += duration;
        return total;
    }
};

int main(){
    Solution sol;
    int n,m,duration;
    cout <<"Enter number of attacks : ";
    cin >> n; 

    vector<int> timeSeries(n);
    cout <<"Enter the start times of each attack : ";
    for(int i = 0; i < n; i++){
        cin >> timeSeries[i];
    }
    cout <<"Enter the duration of each attack : ";
    cin >> duration;

    int result = sol.findPoisonedDuration(timeSeries,duration);
    cout <<"Total poisoned duration: "<< result;

    return 0;
}