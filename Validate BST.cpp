
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) //Where n is the number of nodes in the binary tree.
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
private:
    bool helper(TreeNode* root, long long Min, long long Max){
        if(!root) return true;
        
        // If the current root's value is not in the valid range, return false
        if(root->val <= Min || root->val >= Max)
            return false;

        // Recursively check the left and right subtrees and update the range    
        return helper(root->left, Min, root->val) && 
               helper(root->right, root->val, Max);    
    }    

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <climits>
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
private:
    bool helper(TreeNode* root, long long Min, long long Max){
        if(!root) return true;
        
        // If the current root's value is not in the valid range, return false
        if(root->val <= Min || root->val >= Max)
            return false;

        // Recursively check the left and right subtrees and update the range    
        return helper(root->left, Min, root->val) && 
               helper(root->right, root->val, Max);    
    }    

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
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

    bool isValid = sol.isValidBST(root);
    cout <<"\nIs the binary tree a valid BST? " << (isValid ? "Yes" : "No") << endl;
    
    return 0;
}