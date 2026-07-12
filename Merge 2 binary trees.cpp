
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(h) 

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return nullptr;
        if(!root1) return root2;
        if(!root2) return root1;

        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left,root2->left);
        root->right = mergeTrees(root1->right,root2->right);
        return root;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return nullptr;
        if(!root1) return root2;
        if(!root2) return root1;

        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left,root2->left);
        root->right = mergeTrees(root1->right,root2->right);
        return root;
    }
};

TreeNode* buildTree() {
    int val;
    cout << "Enter root value (-1 for null): ";
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

        cout << "Enter left child of " << current->val << " (-1 for null): ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << " (-1 for null): ";
        cin >> rightVal;

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

void levelOrder(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }
    cout << endl;
}

int main() {
    Solution sol;
    cout << "Build First Tree\n";
    TreeNode* root1 = buildTree();

    cout << "\nBuild Second Tree\n";
    TreeNode* root2 = buildTree();

    TreeNode* mergedRoot = sol.mergeTrees(root1,root2);

    cout << "Level Order Traversal of Merged Tree : \n";
    levelOrder(mergedRoot);

    return 0;
}