
/* ==================== LeetCode version =========================

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
        return false;
        if(root->left == nullptr && root->right == nullptr)
        return targetSum == root->val;
        targetSum = targetSum - root->val;
        
        return hasPathSum(root->left,targetSum) 
        || hasPathSum(root->right,targetSum);
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
        return false;
        if(root->left == nullptr && root->right == nullptr)
        return targetSum == root->val;
        targetSum = targetSum - root->val;
        
        return hasPathSum(root->left,targetSum) 
        || hasPathSum(root->right,targetSum);
    }
};

TreeNode* buildTree(int n) {
    if (n == 0) 
	return nullptr;

    int val;
    cin >> val;
    
    if (val == -1) 
	return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    int count = 1;
    while (!q.empty() && count < n) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        count++;
        
        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        if (count >= n) break;
        cin >> rightVal;
        count++;
        
        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
	Solution sol;
    int n;
    cout << "Enter the number of nodes:\n";
    cin >> n;

    cout << "Enter values in level-order (-1 for null):\n";
    TreeNode* root = buildTree(n);

    int targetSum;
    cout << "Enter target sum:\n";
    cin >> targetSum;

    bool result = sol.hasPathSum(root, targetSum);
    if (result)
        cout << "Path exists! True\n";
    else
        cout << "Path doesn't exist. False\n";

    return 0;
}