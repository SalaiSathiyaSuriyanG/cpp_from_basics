
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(h) 

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;

        int depth = 0;
        for(Node* kid : root->children){
            depth = max(depth,maxDepth(kid));
        }
        return 1 + depth;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;

        int depth = 0;
        for(Node* kid : root->children){
            depth = max(depth,maxDepth(kid));
        }
        return 1 + depth;
    }
};

Node* buildTree() {
    int val;
    cout <<"Enter root value (-1 for null) : ";
    cin >> val;

    if(val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        int numChildren;
        cout <<"Enter the no.of children of " << current->val <<" : ";
        cin >> numChildren;

        for(int i = 0; i < numChildren; i++) {
            int childVal;
            cout <<"Enter child "<< i + 1 << " of "<< current->val <<" : ";
            cin >> childVal;

            Node* child = new Node(childVal);
            current->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

int main(){
    Solution sol;
    Node* root = buildTree();

    cout <<"Maximum depth of tree : "<< sol.maxDepth(root);

    return 0;
}