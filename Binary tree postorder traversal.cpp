
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(h)  // Because of recursion stack. h = height of the tree

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
    void postorder(TreeNode* root,vector<int>& result) {
        if(root == nullptr)
        return;

        postorder(root->left,result);
        postorder(root->right,result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    postorder(root,result);
    return result;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include<iostream>
#include<vector>
#include<queue>
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
    void postorder(TreeNode* root,vector<int>& result) {
        if(root == nullptr)
        return;

        postorder(root->left,result);
        postorder(root->right,result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    postorder(root,result);
    return result;
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

int main() {
	Solution sol;
	TreeNode* root = buildTree();
	
    vector<int> result = sol.postorderTraversal(root);
    cout<<"Postorder Traversal: ";
    for (int val : result) {
        cout<<val<< " ";
    }

    return 0;
}