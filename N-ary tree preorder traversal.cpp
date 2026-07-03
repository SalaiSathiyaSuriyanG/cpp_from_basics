
/* ================================== LeetCode version ======================================

- Time Complexity: O(n) 
- Space Complexity: O(h)  

/*
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
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> result;

        result.push_back(root->val);

        for(Node* node : root->children){
            vector<int> kids = preorder(node);
            result.insert(result.end(),kids.begin(),kids.end());
        }
        return result;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <vector>
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
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> result;

        result.push_back(root->val);

        for(Node* node : root->children){
            vector<int> kids = preorder(node);
            result.insert(result.end(),kids.begin(),kids.end());
        }
        return result;
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
    vector<int> result = sol.preorder(root);

    cout <<"Preorder traversal : ";
    for(auto val : result){
        cout << val <<" ";
    }
    cout << endl;

    return 0;
}