
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(n) // Because of queue usage and recursion stack

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
 /
class Solution {
public:
    TreeNode* invertTree(TreeNode* root,int level = 1) {
        if(root == nullptr)
            return nullptr;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
=============================================================== */

// ==================== Runnable Version =========================

#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
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
    TreeNode* invertTree(TreeNode* root,int level = 1) {
        if(root == nullptr)
            return nullptr;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

TreeNode* buildTree() {
    cout << "Enter the inputs in level order (-1 for null): ";
    vector<int> arr;
    string line;
    getline(cin, line);
    if (line.empty())
        getline(cin, line);

    stringstream ss(line);
    int x;

    while (ss >> x) {
        arr.push_back(x);
    }

    if (arr.empty() || arr[0] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->val << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();
    TreeNode* invertedRoot = sol.invertTree(root);

    cout << "\nInverted tree: ";
    printLevelOrder(invertedRoot);
    cout << endl;

    return 0;
}