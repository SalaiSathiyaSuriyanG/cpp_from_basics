
/* ================================== LeetCode version ======================================

- Time Complexity: O(n)
- Space Complexity: O(n)
//Both time and space complexity is O(n) because we are visiting each node once and in the worst case,we have to store all nodes in the recursion stack.

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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == nullptr)
            return 0;

        if(root->left && !root->left->left && !root->left->right){
            //If the current node has a left child but that left child does not have any child node
            sum += root->left->val;
        }    
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;  
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == nullptr)
            return 0;

        if(root->left && !root->left->left && !root->left->right){
            //If the current node has a left child but that left child does not have any child node
            sum += root->left->val;
        }    
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;  
    }
};

TreeNode* buildTree() {
    int val;
    cout << "Enter the root value (-1 for null): ";
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

        cout << "Enter the left child of " << current->val << " (-1 for null): ";
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout << "Enter the right child of " << current->val << " (-1 for null): ";
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
    cout <<"Sum of left leaves : "<< sol.sumOfLeftLeaves(root);

    return 0;
}