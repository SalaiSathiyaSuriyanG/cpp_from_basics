
/* ================================== LeetCode version ======================================

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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;

        queue<TreeNode*> q;
        q.push(root);
        int minVal = root->val, secondMin = INT_MAX;
        bool found = false;
        
        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode->left != nullptr && currNode->right != nullptr) {
                q.push(currNode->left);
                q.push(currNode->right);

                if(currNode->left->val != minVal) {
                    secondMin = min(secondMin, currNode->left->val);
                    found = true;
                }
                if(currNode->right->val != minVal) {
                    secondMin = min(secondMin, currNode->right->val);
                    found = true;
                }
            }
        }
        return found ? secondMin : -1;
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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;

        queue<TreeNode*> q;
        q.push(root);
        int minVal = root->val, secondMin = INT_MAX;
        bool found = false;
        
        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode->left != nullptr && currNode->right != nullptr) {
                q.push(currNode->left);
                q.push(currNode->right);

                if(currNode->left->val != minVal) {
                    secondMin = min(secondMin, currNode->left->val);
                    found = true;
                }
                if(currNode->right->val != minVal) {
                    secondMin = min(secondMin, currNode->right->val);
                    found = true;
                }
            }
        }
        return found ? secondMin : -1;
    }
};

TreeNode* buildTree() {
    int val;
    cout <<"Enter root value (-1 for null) : ";
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

        cout <<"Enter left child of "<< current->val <<" (-1 for null) : ";
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

    cout <<"\nIf no second min exist, output = -1"<< endl;
    cout <<"\nThe value of second minimum node is : "<< sol.findSecondMinimumValue(root);

    return 0;
}