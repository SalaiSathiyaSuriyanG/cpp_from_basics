
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(h) // h is the height of the tree

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
    int diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }

private:
    int dfs(TreeNode* node){
        if (!node) return -1;  // Height in edges

        int left = dfs(node->left);
        int right = dfs(node->right);

        // Diameter passing through current node
        diameter = max(diameter, left + right + 2);

        // Return height in edges
        return 1 + max(left, right);
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
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
    int diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }

private:
    int dfs(TreeNode* node){
        if (!node) return -1;  // Height in edges

        int left = dfs(node->left);
        int right = dfs(node->right);

        // Diameter passing through current node
        diameter = max(diameter, left + right + 2);

        // Return height in edges
        return 1 + max(left, right);
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

int main(){
    Solution sol;
    TreeNode* root = buildTree();
    int result = sol.diameterOfBinaryTree(root);

    cout <<"Diameter of Binary Tree : " << result;

    return 0;
}