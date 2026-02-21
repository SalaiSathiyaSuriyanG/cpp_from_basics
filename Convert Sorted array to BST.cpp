
/* ==================== LeetCode version =========================

- Time Complexity: O(n)
- Space Complexity: O(log n)

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
vector<int> nums;
    TreeNode* helper(int left,int right){
    if(left > right) 
    return nullptr;

    int mid = left + (right-left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(left,mid-1);
    root->right = helper(mid+1,right);
    return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& a) {
        nums = a;  
        return helper(0,nums.size()-1);
    }
};
=============================================================== */

// ==================== Runnable Version =========================
#include <iostream>
#include <vector>
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
vector<int> nums;
    TreeNode* helper(int left,int right){
    if(left > right) 
    return nullptr;

    int mid = left + (right-left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(left,mid-1);
    root->right = helper(mid+1,right);
    return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& a) {
        nums = a;  
        return helper(0,nums.size()-1);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    TreeNode* root = sol.sortedArrayToBST(arr);

    cout << "Level Order Traversal: ";

    if (root == nullptr) return 0;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    
    return 0;
}