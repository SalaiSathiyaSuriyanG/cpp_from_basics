
/* ==================== LeetCode version =========================

- Time Complexity: O(log² n) // The height of the tree is log(n) and we calculate the height for left and right subtree, 
                                leading to log(n) * log(n) = log²(n).
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
 /
class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode* L = root;
        TreeNode* R = root;

        int L_height = 0, R_height = 0;

        while (L) {
            L_height++;
            L = L->left;
        }

        while (R) {
            R_height++;
            R = R->right;
        }

        if (L_height == R_height)
            return (1 << L_height) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
=============================================================== */

// ==================== Runnable Version =========================

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
    int countNodes(TreeNode* root) {
        TreeNode* L = root;
        TreeNode* R = root;

        int L_height = 0, R_height = 0;

        while (L) {
            L_height++;
            L = L->left;
        }

        while (R) {
            R_height++;
            R = R->right;
        }

        if (L_height == R_height)
            return (1 << L_height) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

TreeNode* buildTree() {
    int val;
    cin >> val;

    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        int leftVal, rightVal;

        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new TreeNode(leftVal);
            q.push(curr->left);
        }

        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new TreeNode(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

int main() {
    Solution sol;
    cout << "Enter tree nodes in level order (-1 for NULL) : \n";

    TreeNode* root = buildTree();
    int result = sol.countNodes(root);

    cout << "Total nodes: " << result;

    return 0;
} 