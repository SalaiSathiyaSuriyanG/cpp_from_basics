
/* ================================== LeetCode version ======================================

- Time Complexity: O(n log n + m log m) //Where n is the number of children and m is the number of cookies
- Space Complexity: O(1) 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j = 0;

        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }
        return i;
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0, j = 0;

        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};

int main() {
    Solution sol;
    int g, s;

    cout <<"Enter the number of children : ";
    cin >> g;

    cout <<"Enter the number of cookies : ";
    cin >> s;

    vector<int> greedy(g);
    vector<int> size(s);

    cout <<"Enter the greed factors of children : ";
    for (int i = 0; i < g; i++) {
        cin >> greedy[i];
    }

    cout <<"Enter the sizes of cookies : ";
    for (int i = 0; i < s; i++) {
        cin >> size[i];
    }
    cout <<"Satisfied children: "<< sol.findContentChildren(greedy, size);

    return 0;
}