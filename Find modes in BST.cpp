
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) //n is the number of nodes and k is the number of unique values. O(n+k) = O(n) since k<=n
- Space Complexity: O(n) //In the worst case,all values are frequently occurred elements.

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:
    void dfs(TreeNode* node,unordered_map<int,int>& freq){
        if(!node) return;

        //Count the frequency of each node->val
        freq[node->val]++;
        dfs(node->left,freq);
        dfs(node->right,freq);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        dfs(root,freq);

        int maxFreq = 0;
        vector<int> result;

        for(auto& pair : freq){ //Iterate through each pair of the map and find the max freq.
            maxFreq = max(maxFreq,pair.second);
        }

        //If the freq of a num == maxFreq,push that num to the result vector.
        for(auto& pair : freq){
            if(pair.second == maxFreq) 
                result.push_back(pair.first);
        }
        return result;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* node,unordered_map<int,int>& freq){
        if(!node) return;

        //Count the frequency of each node->val
        freq[node->val]++;
        dfs(node->left,freq);
        dfs(node->right,freq);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        dfs(root,freq);

        int maxFreq = 0;
        vector<int> result;

        for(auto& pair : freq){ //Iterate through each pair of the map and find the max freq.
            maxFreq = max(maxFreq,pair.second);
        }

        //If the freq of a num == maxFreq,push that num to the result vector.
        for(auto& pair : freq){
            if(pair.second == maxFreq) 
                result.push_back(pair.first);
        }
        return result;
    }
};

TreeNode* buildTree() {
    int val;
    cout <<"Enter root value (-1 for null) : ";
    cin >> val;

    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;

        cout <<"Enter left child of "<< current->val <<" (-1 for null) : ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout <<"Enter right child of "<< current->val <<" (-1 for null) : ";
        cin >> rightVal;

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

int main(){
    Solution sol;
    TreeNode* root = buildTree();

    cout <<"Mode(s) in the binary tree : ";
    vector<int> modes = sol.findMode(root);
    for (int mode : modes) {
        cout << mode <<" ";
    }
    cout << endl;

    return 0;
}