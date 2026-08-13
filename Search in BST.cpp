
/* ================================== LeetCode version ======================================

- Time Complexity: O(h) 
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;

        /*
        In a binary search tree, all values of left side of current root are less than the root value 
        and all values of right side of current root are greater than the root value.
        /

        if(root->val == val)
            return root;
        else if(root->val > val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);    
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;

        /*
        In a binary search tree, all values of left side of current root are less than the root value 
        and all values of right side of current root are greater than the root value.
        */

        if(root->val == val)
            return root;
        else if(root->val > val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);    
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

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->val <<"  ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main(){
    Solution sol;
    TreeNode* root = buildTree();
    int val;

    cout <<"Enter value to search : ";
    cin >> val;

    TreeNode* result = sol.searchBST(root, val);
    if(result){
    cout <<"\nNodes in the subtree rooted with the searched value : ";
    printTree(result);
    }
    else
        cout <<"\nValue not found in the BST.";

    return 0;
}