#include <iostream>
#include <vector>
#include <map>
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

// Used for printing result of tree construction
void print_pre_order(Node* root) {
    if(root == nullptr)
        return;
    
    cout << root->data << " ";
    print_pre_order(root->left);
    print_pre_order(root->right);
}

/**
 * Construct a "Unique" binary tree, given its 'in-order' and 'pre-order' sequence.
 * Approach:
 * 1. We find the root from 'pre-order' and split the 'in-order' sequence into 'left' subtree
 * and 'right' subtree.
 * 2. We then call the recursive function with left and right sub trees and repeat.
 */
Node* construct_tree(vector<int> &in, int inStart, int inEnd, vector<int> &pre, int preStart, int preEnd, map<int, int> inMap) {
    // Base condition
    if(inStart > inEnd || preStart > preEnd)
        return nullptr;

    // Process
    // 1. Create the root node
    Node* root = new Node(pre[preStart]);

    // 2. Identify root's index in in-order
    int rootIdx = inMap[root->data];
    int leftRange = rootIdx - inStart;

    // Recursive calls
    root->left = construct_tree(in, inStart, rootIdx - 1, pre, preStart + 1, preStart + leftRange, inMap);
    root->right = construct_tree(in, rootIdx + 1, inEnd, pre, preStart + leftRange + 1, preEnd, inMap);
    return root;
}

int main() {
    vector<int> in = {40,20,50,10,60,30};
    vector<int> pre = {10,20,40,50,30,60};

    // Hash the in-order sequence as we'll need to find every node's position frequently.
    map<int, int> inMap;
    for(int i = 0; i < in.size(); i++) {
        inMap[in[i]] = i;
    }

    // Call the recursive function with 'map'
    Node* root = construct_tree(in, 0, in.size() - 1, pre, 0, pre.size() - 1, inMap);
    cout << "Printing result in pre-order: " << endl;
    print_pre_order(root);
    return 0;
}