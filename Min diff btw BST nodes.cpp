
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(1) 

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
    int minDiff = INT_MAX;
    int prev = 0;
    bool hasPrev = false;

private:
    void helper(TreeNode* root) {
        if (!root) return;

        helper(root->left);
        if(hasPrev){
            minDiff = min(minDiff, abs(prev - root->val));
        }

        prev = root->val;
        hasPrev = true;
        helper(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        helper(root);
        return minDiff;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
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
    int minDiff = INT_MAX;
    int prev = 0;
    bool hasPrev = false;

private:
    void helper(TreeNode* root) {
        if (!root) return;

        helper(root->left);
        if(hasPrev){
            minDiff = min(minDiff, abs(prev - root->val));
        }

        prev = root->val;
        hasPrev = true;
        helper(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        helper(root);
        return minDiff;
    }
};

TreeNode* buildTree(){
    int val;
    cout <<"Enter root value (-1 for null) : ";
    cin >> val;

    if(val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;

        cout <<"Enter left child of " << current->val << " (-1 for null) : ";
        cin >> leftVal;

        if(leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout <<"Enter right child of " << current->val << " (-1 for null) : ";
        cin >> rightVal;

        if(rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

int main(){
    Solution sol;
    TreeNode* root = buildTree();
    int result = sol.minDiffInBST(root);

    cout <<"\nMinimum difference in BST : " << result << endl;

    return 0;
}