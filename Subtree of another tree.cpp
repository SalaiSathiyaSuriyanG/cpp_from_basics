
/* ================================== LeetCode version ======================================

- Time Complexity: O(n*m) //where n is the number of nodes in the tree and m is the number of nodes in the subtree.
- Space Complexity: O(h1 + h2) //where h1 is the height of the tree and h2 is the height of the subtree.

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
    bool isSameTree(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;

        return isSameTree(a->left,b->left) && isSameTree(a->right,b->right);
    }

    bool helper(TreeNode* a, TreeNode* b){
        if(!a) return false;
        if (isSameTree(a,b)) return true;

        return helper(a->left,b) || helper(a->right,b);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
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
    bool isSameTree(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val != b->val) return false;

        return isSameTree(a->left,b->left) && isSameTree(a->right,b->right);
    }

    bool helper(TreeNode* a, TreeNode* b){
        if(!a) return false;
        if (isSameTree(a,b)) return true;

        return helper(a->left,b) || helper(a->right,b);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
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

        cout <<"Enter left child of "<< current->val <<" (-1 for null)  : ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout <<"Enter right child of "<< current->val <<" (-1 for null) : ";
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
    TreeNode* subRoot = buildTree();

    bool result = sol.isSubtree(root, subRoot);
    cout <<"Is subRoot a subtree of root? : "<< (result ? "Yes" : "No");

    return 0;
}