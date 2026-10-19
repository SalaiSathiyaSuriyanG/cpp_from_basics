
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) //Where n is the number of nodes in the BST.
- Space Complexity: O(h) //Where h is the height of the BST.

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
    void BST(TreeNode* node, int l, int h, int& sum){
        if(!node) return;

        // If the curr node value is within the range, add it to sum. 
        if(node->val >= l && node->val <= h){
            sum += node->val;
        }
        
        // Check the left subtree
        // only if the curr node value is greater than low.
        if(node->val > l)
            BST(node->left, l, h, sum);
        
        // Check the right subtree
        // only if the curr node value is smaller than high.
        if(node->val < h)
            BST(node->right, l, h, sum);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        BST(root, low, high, sum);
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
private:
    void BST(TreeNode* node, int l, int h, int& sum){
        if(!node) return;

        // If the curr node value is within the range, add it to sum. 
        if(node->val >= l && node->val <= h){
            sum += node->val;
        }
        
        // Check the left subtree
        // only if the curr node value is greater than low.
        if(node->val > l)
            BST(node->left, l, h, sum);
        
        // Check the right subtree
        // only if the curr node value is smaller than high.
        if(node->val < h)
            BST(node->right, l, h, sum);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        BST(root, low, high, sum);
        return sum;
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
    
    int low, high;
    cout <<"\nEnter the range [low, high] :" << endl;
    cin >> low >> high;

    int result = sol.rangeSumBST(root, low, high);
    cout <<"\nRange sum : " << result;

    return 0;
} 