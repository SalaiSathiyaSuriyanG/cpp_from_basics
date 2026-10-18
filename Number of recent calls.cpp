
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) //Where n is the number of pings.
- Space Complexity: O(n) //We are storing the pings in a queue.

class RecentCounter {
private:
    queue<int> q;
public:
    //RecentCounter() {}
    
    int ping(int t) {
        q.push(t);

        // Remove the requests that are older than t-3000.
        while(!q.empty() && q.front() < (t - 3000)) q.pop();
        
        return q.size();
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
private:
    queue<int> q;
public:
    //RecentCounter() {}
    
    int ping(int t) {
        q.push(t);

        // Remove the requests that are older than t-3000.
        while(!q.empty() && q.front() < (t - 3000)) q.pop();
        
        return q.size();
    }
};

int main(){
    RecentCounter sol;
    int n, t;
    cout <<"Enter the number of pings : ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout <<"\nEnter the time of ping : ";
        cin >> t;
        cout <<"Number of recent requests at "<< t <<" : " << sol.ping(t) << endl;
    }

    return 0;
}