
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
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
    void helper(TreeNode* root,int k,int &count, int &result){
        if(!root) return;

        helper(root->left, k, count, result);
        count++;

        if(count == k){
            result = root->val;
            return;
        }
        else
            helper(root->right, k, count, result);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result;
        helper(root, k, count, result);

        return result;
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
private:
    void helper(TreeNode* root,int k,int &count, int &result){
        if(!root) return;

        helper(root->left, k, count, result);
        count++;

        if(count == k){
            result = root->val;
            return;
        }
        else
            helper(root->right, k, count, result);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result;
        helper(root, k, count, result);

        return result;
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
    int k;
    cout <<"\nEnter the value of k : ";
    cin >> k;

    cout <<"\nThe 'k'th smallest element is : "<< sol.kthSmallest(root, k) << endl;
    
    return 0;
}