
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
    bool isMirror(TreeNode* n1,TreeNode* n2){
        if(n1 == nullptr && n2 == nullptr)
        return true;
        if(n1 == nullptr || n2 == nullptr)
        return false;    
        if(n1-> val != n2-> val)
        return false;

        return isMirror(n1->left,n2->right) &&
               isMirror(n1->right,n2->left);    
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
        return true;

        return isMirror(root->left,root->right);
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
    bool isMirror(TreeNode* n1,TreeNode* n2){
        if(n1 == nullptr && n2 == nullptr)
        return true;
        if(n1 == nullptr || n2 == nullptr)
        return false;    
        if(n1-> val != n2-> val)
        return false;

        return isMirror(n1->left,n2->right) &&
               isMirror(n1->right,n2->left);    
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
        return true;

        return isMirror(root->left,root->right);
    }
};

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        
        if (nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
	Solution obj;
    cout << "Enter tree nodes in level order (use 'null' for empty nodes):\n";

    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<string> nodes;
    string temp;
    while (ss >> temp) {
        nodes.push_back(temp);
    }

    TreeNode* root = buildTree(nodes);
    bool result = obj.isSymmetric(root);

    if(result)
        cout << "Tree is symmetric\n";
    else
        cout << "Tree is NOT symmetric\n";

    return 0;
}
