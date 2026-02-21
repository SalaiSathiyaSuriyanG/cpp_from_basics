
/* ==================== LeetCode version =========================

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
    int checkHeight(TreeNode* root) {
        if(root == nullptr)
        return 0;

        int left_H = checkHeight(root->left);
        int right_H = checkHeight(root->right);

        if(left_H == -1) 
        return -1;
        if(right_H == -1) 
        return -1;
        if(abs(left_H - right_H) > 1)
        return -1;

        return 1 + max(left_H, right_H);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <queue>
#include <cmath>
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
    int checkHeight(TreeNode* root) {
        if(root == nullptr)
        return 0;

        int left_H = checkHeight(root->left);
        int right_H = checkHeight(root->right);

        if(left_H == -1) 
        return -1;
        if(right_H == -1) 
        return -1;
        if(abs(left_H - right_H) > 1)
        return -1;

        return 1 + max(left_H, right_H);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

int main() {
	Solution sol;
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;

    if(n == 0) {
        cout << "Tree is Balanced\n";
        return 0;
    }

    cout << "Enter nodes in level order (-1 for NULL):\n";
    int val;
    cin >> val;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    int count = 1;
    while(count < n) {
        TreeNode* current = q.front();
        q.pop();
        cin >> val;
        count++;
        
        if(val != -1) {
            current->left = new TreeNode(val);
            q.push(current->left);
        }

        if(count >= n) 
		break;
        cin >> val;
        count++;
        
        if(val != -1) {
            current->right = new TreeNode(val);
            q.push(current->right);
        }
    }

    if(sol.isBalanced(root))
        cout << "Tree is Balanced\n";
    else
        cout << "Tree is NOT Balanced\n";

    return 0;
}