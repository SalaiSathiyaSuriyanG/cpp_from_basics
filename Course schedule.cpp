
/* ================================== LeetCode version ======================================

- Time Complexity: O(V + E)  //Where V = number of courses (vertices/nodes) and E = number of prerequisite pairs (edges).
- Space Complexity: O(V + E) 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];         //Stores the neighbors (adj[i] contains nodes connected from i)
        vector<int> indegree(n,0);  //Stores the number of incoming edges for each node
        vector<int> result;

        for(auto x : prerequisites){      //Builds the graph and calculates the indegree of each node.
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){   // Find all nodes with no incoming edges and add them to the queue.
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){       
            auto f = q.front();
            result.push_back(f);
            q.pop();

            for(auto x : adj[f]){    //Finishing one course may unlock other courses. This loop finds and unlocks them.
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        return result.size() == n;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];         //Stores the neighbors (adj[i] contains nodes connected from i)
        vector<int> indegree(n,0);  //Stores the number of incoming edges for each node
        vector<int> result;

        for(auto x : prerequisites){      //Builds the graph and calculates the indegree of each node.
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){   // Find all nodes with no incoming edges and add them to the queue.
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){    // Process all available nodes in topological order.
            auto f = q.front();
            result.push_back(f);
            q.pop();

            for(auto x : adj[f]){    // Update neighbors. If a neighbor has no remaining dependencies, add it to queue.
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        return result.size() == n;
    }
};

int main() {
    Solution sol;
    int numCourses,n;

    cout <<"Enter number of courses : ";
    cin >> numCourses;

    cout <<"Enter number of prerequisite pairs : ";
    cin >> n;
    cout << endl;

    vector<vector<int>> prerequisites;

    cout <<"Enter each prerequisite pair as : course  prerequisite"<< endl;
    cout <<"Example: 1  0 means 'to take course 1, you must first take course 0'"<< endl;

    for (int i = 0; i < n; i++) {
        int course,prerequisite;

        cout <<"\nPair " << i + 1 << ": ";
        cin >> course >> prerequisite;

        prerequisites.push_back({course,prerequisite});
    }

    if (sol.canFinish(numCourses, prerequisites))
        cout <<"Yes, all courses can be completed."<< endl;
    else
        cout <<"No, all courses cannot be completed (cycle detected)."<< endl;

    return 0;
}