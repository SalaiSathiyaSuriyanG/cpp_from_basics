
/* ================================== LeetCode Version ======================================

- Time Complexity: O(m + n) //Where m is the number of nodes in the first tree and n is the number of nodes in the second tree.
- Space Complexity: O(m + n) 

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
/
class Solution {
private:
    void dfs(TreeNode* node, vector<int>& sum){
        if(!node) return;

        if(!node->left && !node->right){
            sum.push_back(node->val);
        }
        dfs(node->left, sum);
        dfs(node->right, sum);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sum1;
        vector<int> sum2;

        dfs(root1, sum1);
        dfs(root2, sum2);

        return sum1 == sum2;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

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
private:
    void dfs(TreeNode* node, vector<int>& sum){
        if(!node) return;

        if(!node->left && !node->right){
            sum.push_back(node->val);
        }
        dfs(node->left, sum);
        dfs(node->right, sum);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sum1;
        vector<int> sum2;

        dfs(root1, sum1);
        dfs(root2, sum2);

        return sum1 == sum2;
    }
};

TreeNode* buildTree(){
    int val;
    cout <<"Enter root value (-1 for null) : ";
    cin >> val;

    if(val == -1)
        return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;

        cout <<"Enter left child of " << current->val << " (-1 for null) : ";
        cin >> leftVal;

        if(leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cout <<"Enter right child of " << current->val << " (-1 for null) : ";
        cin >> rightVal;

        if(rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

int main(){
    Solution sol;
    TreeNode* root1 = buildTree();
    TreeNode* root2 = buildTree();

    cout <<"Are the two trees leaf-similar? : " << (sol.leafSimilar(root1, root2) ? "Yes" : "No") << endl;

    return 0;
}