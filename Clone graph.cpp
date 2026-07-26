
/* ================================== LeetCode version ======================================

- Time Complexity: O(V + E) //Where V = Number of vertices(nodes) and E = Number of edges.
- Space Complexity: O(V) //Due to Hash map and recursion stack. 

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*,Node*> map;
    //For the algorithm to work, all nodes must share one single map so they can see what has already been copied. That's why it is outside the function.

    Node* cloneGraph(Node* node) {
        if(!node) return 0;

        Node* copy = new Node(node->val);
        map[node] = copy;

        for(auto i : node->neighbors){
            //If the neighbor has already been cloned (stored in map),connect the current cloned node (copy) to the existing cloned neighbor (map[i]).
            if(map.count(i)){
                copy->neighbors.push_back(map[i]);
            }

            //If not, clone it recursively and then connect it as a neighbor.
            else{
                copy->neighbors.push_back(cloneGraph(i));
            }
        }
        return copy;
    }
};
========================================================================================== */

// ================================== Runnable Version ======================================

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*,Node*> map;
    //For the algorithm to work, all nodes must share one single map so they can see what has already been copied. That's why it is outside the function.

    Node* cloneGraph(Node* node) {
        if(!node) return 0;

        Node* copy = new Node(node->val);
        map[node] = copy;

        for(auto i : node->neighbors){
            //If the neighbor has already been cloned (stored in map),connect the current cloned node (copy) to the existing cloned neighbor (map[i]).
            if(map.count(i)){
                copy->neighbors.push_back(map[i]);
            }

            //If not, clone it recursively and then connect it as a neighbor.
            else{
                copy->neighbors.push_back(cloneGraph(i));
            }
        }
        return copy;
    }
};

void printGraph(Node* node, unordered_set<Node*>& vis) {
    if (!node || vis.count(node)) return;

    vis.insert(node);

    cout << node->val << " -> ";
    for (auto x : node->neighbors)
        cout << x->val << "   ";
    cout << endl;

    for (auto x : node->neighbors)
        printGraph(x, vis);
}

int main() {
    Solution sol;
    int n;
    cout <<"Enter the number of nodes: ";
    cin >> n;

    vector<Node*> nodes(n + 1);
    for (int i = 1; i <= n; i++)
        nodes[i] = new Node(i);

    cout <<"\nEnter the neighbors for each node.\n";

    for (int i = 1; i <= n; i++) {
        int m;
        cout <<"\nHow many neighbors does Node " << i << " have ? : ";
        cin >> m;

        cout << "Enter the neighbors of Node " << i << ": ";
        while (m--) {
            int x;
            cin >> x;
            nodes[i]->neighbors.push_back(nodes[x]);
        }
    }

    Node* clone = sol.cloneGraph(nodes[1]);
    unordered_set<Node*> visited;

    cout <<"\nOriginal Graph:\n";
    printGraph(nodes[1],visited);

    visited.clear();

    cout <<"\nCloned Graph:\n";
    printGraph(clone,visited);

    return 0;
}