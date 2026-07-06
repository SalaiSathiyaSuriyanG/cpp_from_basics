
/* ================================== LeetCode version ======================================

- Time Complexity: O(k) //where k is the no.of operations 
- Space Complexity: O(1) 

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0) return m*n;

        int row = m,col = n;
        for(int i = 0; i < ops.size(); i++){
            row = min(row,ops[i][0]);
            col = min(col,ops[i][1]);
        }
        return row*col;
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
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0) return m*n;

        int row = m,col = n;
        for(int i = 0; i < ops.size(); i++){
            row = min(row,ops[i][0]);
            col = min(col,ops[i][1]);
        }
        return row*col;
    }
};

int main() {
    Solution sol;
    int m,n;
    cout <<"Enter the number of rows and columns : ";
    cin >> m >> n;

    int numOps;
    cout << "Enter the number of operations : ";
    cin >> numOps;

    vector<vector<int>> ops;

    cout <<"Enter each operation (a,b) :\n";
    for (int i = 0; i < numOps; i++) {
        int a, b;
        cin >> a >> b;
        ops.push_back({a, b});
    }

    cout <<"Maximum count = "<< sol.maxCount(m,n,ops);

    return 0;
}