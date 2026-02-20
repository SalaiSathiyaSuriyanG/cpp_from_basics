
/* ==================== LeetCode version =========================

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
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        return 0;

        return 1+ max(maxDepth(root-> left),maxDepth(root-> right));
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <queue>
#include <vector>
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        return 0;

        return 1+ max(maxDepth(root-> left),maxDepth(root-> right));
    }
};

TreeNode* buildTree() {
    int val;
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

        cin >> leftVal;
        if(leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cin >> rightVal;
        if(rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
	Solution sol;
    cout << "Enter nodes in level order (-1 for null):\n";
    TreeNode* root = buildTree();
    cout << "Maximum Depth: " << sol.maxDepth(root) << endl;

    return 0;
}