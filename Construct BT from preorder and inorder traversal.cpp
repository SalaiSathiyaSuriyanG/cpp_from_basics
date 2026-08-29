
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) //Because of the map and recursive stack calls in build().

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
    int preorderIndex;
    unordered_map<int,int> map;

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex];
        preorderIndex++;

        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map.clear();
        
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <unordered_map>
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
    int preorderIndex;
    unordered_map<int,int> map;

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start > end) return nullptr;

        int rootVal = preorder[preorderIndex];
        preorderIndex++;

        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];

        root->left = build(preorder, start, mid - 1);
        root->right = build(preorder, mid + 1, end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map.clear();
        
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        preorderIndex = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
};

void printInorder(TreeNode* root) {
    if(!root) return;

    printInorder(root->left);
    cout << root->val <<" ";
    printInorder(root->right);
}

int main(){
    Solution sol;
    int n;
    cout <<"Enter the number of elements in Preorder and Inorder array : ";
    cin >> n;

    cout <<"\nPreorder : Root | Left | Right"<< endl;
    vector<int> preorder(n);
    cout <<"Enter the elements of Preorder array :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> preorder[i];
    }

    cout <<"\nInorder : Left | Root | Right"<< endl;
    vector<int> inorder(n);
    cout <<"Enter the elements of Inorder array :"<< endl;
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }

    TreeNode* root = sol.buildTree(preorder, inorder);

    cout <<"\nConstructed binary tree (Inorder traversal) : ";
    printInorder(root);
    cout << endl;

    return 0;
}