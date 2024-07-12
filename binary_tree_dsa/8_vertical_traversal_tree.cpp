#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = nullptr;
        }
};

/**
 * Approach:
 * 1. We'll traverse the entire tree nodes using any traversal techniques ans store in queue.
 * 2. We'll store node's 'vertifcal axis' and its 'level' info in queue "q".
 * 3. We'll have a data structure "nodes" to store (vertical, level, node->data).
 * 4. For nodes on same level and vertical we'll sort them by their values.
 */
vector<vector<int>> vertical_traversal(Node* root) {
    // Define data structures
    vector<vector<int>> result; // holds final result (list of nodes in each vertical)
    queue<pair<Node*, pair<int, int>>> q; // helps with tree traversal in level-order technique
    map<int, map<int, multiset<int>>> nodes; // main data structure to hold 'vertical' and 'level' info in sorted order.
    
    if(root == nullptr)
        return result;

    q.push({root, {0,0}}); // {0,0} => {vertical, level}

    while(!q.empty()) {
        // Get the 'node' data from 'queue'
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int data = node->data;
        int vertical = p.second.first;
        int level = p.second.second;
        
        // Process: add node info to 'nodes' data structure
        nodes[vertical][level].insert(data);

        // Append node's children to 'queue'
        if(node->left) q.push({node->left, {vertical - 1, level + 1}});
        if(node->right) q.push({node->right, {vertical + 1, level + 1}});
    }

    for(auto ver: nodes) {
        vector<int> col;
        for(auto lev: ver.second) {
            col.insert(col.end(), lev.second.begin(), lev.second.end());
        }
        result.push_back(col);
    }

    return result;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    vector<vector<int>> result = vertical_traversal(root);
    cout << "Vertical traversal:\n";
    for(auto i: result) {
        for(auto j: i) {
            cout << j << " ";
        }
    }

    return 0;
}