
/* ================================== LeetCode Version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(n) //Because of the map and recursive stack calls in build().

/**
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
    int postOrderIndex;
    unordered_map<int, int> map;

    TreeNode* build(vector<int>& postorder, int start, int end){
        if(start > end) return nullptr;

        int rootVal = postorder[postOrderIndex];
        postOrderIndex--;

        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];

        root->right = build(postorder, mid + 1, end);
        root->left = build(postorder, start, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map.clear();

        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        
        postOrderIndex = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
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
    int postOrderIndex;
    unordered_map<int, int> map;

    TreeNode* build(vector<int>& postorder, int start, int end){
        if(start > end) return nullptr;

        int rootVal = postorder[postOrderIndex];
        postOrderIndex--;

        TreeNode* root = new TreeNode(rootVal);
        int mid = map[rootVal];

        root->right = build(postorder, mid + 1, end);
        root->left = build(postorder, start, mid - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map.clear();

        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        
        postOrderIndex = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
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
    cout <<"Enter the number of elements in Postorder and Inorder array : ";
    cin >> n;

    cout <<"\nPostorder : Left | Right | Root"<< endl;
    vector<int> postorder(n);
    cout <<"Enter the elements of Postorder array :\n";
    for(int i = 0; i < n; i++){
        cin >> postorder[i];
    }

    cout <<"\nInorder : Left | Root | Right"<< endl;
    vector<int> inorder(n);
    cout <<"Enter the elements of Inorder array :\n";
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }

    TreeNode* root = sol.buildTree(inorder, postorder);

    cout <<"\nConstructed binary tree (in Inorder traversal) : ";
    printInorder(root);
    cout << endl;

    return 0;
}