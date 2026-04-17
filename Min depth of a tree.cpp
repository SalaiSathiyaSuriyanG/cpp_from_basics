
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
        return 0;

        if(root->left!=nullptr && root->right==nullptr)
        return 1 + minDepth(root->left);
        if(root->right!=nullptr && root->left==nullptr)
        return 1 + minDepth(root->right);

        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};
=============================================================== */

// ==================== Runnable Version =========================
#include <iostream>
#include <queue>
#include <algorithm>
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
        return 0;

        if(root->left!=nullptr && root->right==nullptr)
        return 1 + minDepth(root->left);
        if(root->right!=nullptr && root->left==nullptr)
        return 1 + minDepth(root->right);

        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};

TreeNode* buildTree() {
    int val;
    cin >> val;

    if (val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        int leftVal, rightVal;

        cin >> leftVal;
        if (leftVal != -1) {
            node->left = new TreeNode(leftVal);
            q.push(node->left);
        }

        cin >> rightVal;
        if (rightVal != -1) {
            node->right = new TreeNode(rightVal);
            q.push(node->right);
        }
    }

    return root;
}

int main() {
	Solution sol;
	
    cout << "Enter tree values in level order (-1 for null):\n";
    TreeNode* root = buildTree();

    cout << "Minimum depth of the tree: " << sol.minDepth(root) << endl;

    return 0;
}