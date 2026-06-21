
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(h) //Where h is the height of the tree 

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
    void ans(TreeNode* root,vector<int>& result){
        if(root == nullptr) return;

        ans(root->left,result);
        result.push_back(root->val);
        ans(root->right,result);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> result;
        ans(root,result);

        int minDiff = INT_MAX;
        for(int i = 0; i < result.size() - 1; i++){
            minDiff = min(minDiff,abs(result[i] - result[i + 1]));
        } 
        return minDiff;
    }
};
======================================================================================= */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <climits>
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
    void ans(TreeNode* root,vector<int>& result){
        if(root == nullptr) return;

        ans(root->left,result);
        result.push_back(root->val);
        ans(root->right,result);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> result;
        ans(root,result);

        int minDiff = INT_MAX;
        for(int i = 0; i < result.size() - 1; i++){
            minDiff = min(minDiff,abs(result[i] - result[i + 1]));
        } 
        return minDiff;
    }
};

TreeNode* buildTree() {
    int val;
    cout << "Enter root value (-1 for null) : ";
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

        cout << "Enter left child of " << current->val << " (-1 for null) : ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << " (-1 for null) : ";
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
    int minDiff = sol.getMinimumDifference(root);

    cout <<"Minimum absolute difference between values of any two nodes is : "<< minDiff;

    return 0;
}