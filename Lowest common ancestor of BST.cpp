
/* ================================== LeetCode Version ======================================

- Time Complexity: O(h) //Where h is the height of the tree
- Space Complexity: O(1) 

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        if((root->val > p->val) && (root->val > q->val)){
            return lowestCommonAncestor(root->left, p, q);
        }
        if((root->val < p->val) && (root->val < q->val)){
            return lowestCommonAncestor(root->right, p, q);
        }
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        if((root->val > p->val) && (root->val > q->val)){
            return lowestCommonAncestor(root->left, p, q);
        }
        if((root->val < p->val) && (root->val < q->val)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
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
    int p,q;
    cout <<"\nEnter value of node p : ";
    cin >> p;
    cout <<"Enter value of node q : ";
    cin >> q;

    TreeNode* result = sol.lowestCommonAncestor(root, new TreeNode(p), new TreeNode(q));
    cout <<"Lowest Common Ancestor : " << result->val << endl;

    return 0;
}