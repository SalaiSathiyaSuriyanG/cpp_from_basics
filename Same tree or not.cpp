
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(h)  // Because of recursion stack. h = height of the tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {             
        if(p == nullptr && q== nullptr)
        return true;  
        if(p == nullptr || q== nullptr)
        return false;             
        if(p->val != q->val)
        return false;

        return isSameTree(p->left,q->left) && 
        isSameTree(p->right,q->right);
    }
};
=============================================================== */

// ==================== Runnable Version =========================
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
    bool isSameTree(TreeNode* p, TreeNode* q) {             
        if(p == nullptr && q== nullptr)
        return true;  
        if(p == nullptr || q== nullptr)
        return false;             
        if(p->val != q->val)
        return false;

        return isSameTree(p->left,q->left) && 
        isSameTree(p->right,q->right);
    }
};

TreeNode* buildTree(int n) {
    if (n == 0) return nullptr;

    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    int count = 1;

    while (!q.empty() && count < n) {
        TreeNode* current = q.front();
        q.pop();
        cin >> val;
        count++;
        
        if (val != -1) {
            current->left = new TreeNode(val);
            q.push(current->left);
        }

        if (count >= n) break;
        cin >> val;
        count++;
        if (val != -1) {
            current->right = new TreeNode(val);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
	Solution sol;
    int n1, n2;

    cout << "Enter number of nodes for first tree:\n";
    cin >> n1;
    cout << "Enter level order values (-1 for null):\n";
    TreeNode* p = buildTree(n1);

    cout << "Enter number of nodes for second tree:\n";
    cin >> n2;
    cout << "Enter level order values (-1 for null):\n";
    TreeNode* q = buildTree(n2);

    bool result = sol.isSameTree(p, q);

    if (result)
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}