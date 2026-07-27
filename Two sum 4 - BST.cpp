
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) //In the worst case, HashSet stores all the node values

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
    unordered_set<int> set;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        if(set.count(k - root->val)) return true;
        
        set.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <unordered_set>
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
    unordered_set<int> set;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        if(set.count(k - root->val)) return true;
        
        set.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
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

int main(){
    Solution sol;

    TreeNode* root = buildTree();
    int k;
    
    cout << endl;
    cout <<"Enter the target : ";
    cin >> k;

    cout <<"Are there any pairs that sum up to "<< k <<" ?  ";
    if(sol.findTarget(root,k))
        cout <<"Yes";
    else
        cout <<"No";

    return 0;    
}