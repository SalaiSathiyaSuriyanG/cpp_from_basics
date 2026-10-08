
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) //Where n is the number of nodes in the tree.
- Space Complexity: O(h) //Where h is the height of the tree.

/**
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
    TreeNode* temp;
private:
    void inorder(TreeNode* node) {
        if(!node) return;
        
        inorder(node->left);

        node->left = nullptr;  // Cut the left link of the original tree.
        temp->right = node;    // Link the current node as the right child of temp node.
        temp = node;           // Move temp forward to the current node.
        
        inorder(node->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode();
        temp = dummy;

        inorder(root);
        return dummy->right;
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
    TreeNode* temp;
private:
    void inorder(TreeNode* node) {
        if(!node) return;
        
        inorder(node->left);

        node->left = nullptr;  // Cut the left link of the original tree.
        temp->right = node;    // Link the current node as the right child of temp node.
        temp = node;           // Move temp forward to the current node.
        
        inorder(node->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode();
        temp = dummy;

        inorder(root);
        return dummy->right;
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
    TreeNode* result = sol.increasingBST(root);

    cout <<"\nInorder traversal of the new tree : ";
    while(result){
        cout << result->val <<" ";
        result = result->right;
    }
    cout << endl;

    return 0;
}