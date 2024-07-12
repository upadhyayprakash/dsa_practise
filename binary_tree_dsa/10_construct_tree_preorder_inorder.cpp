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
Node* construct_tree_pre_and_in(vector<int> &in, int inStart, int inEnd, vector<int> &pre, int preStart, int preEnd, map<int, int> inMap) {
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
    root->left = construct_tree_pre_and_in(in, inStart, rootIdx - 1, pre, preStart + 1, preStart + leftRange, inMap);
    root->right = construct_tree_pre_and_in(in, rootIdx + 1, inEnd, pre, preStart + leftRange + 1, preEnd, inMap);
    return root;
}


/** Construct a 'Unique' binary tree from the given 'Post-order' and 'In-order' sequences.
 * Approach:
 * 1. It's similar to 'pre-order' & 'in-order' problem above.
 * 2. Only difference being, 'post-order' will have its 'root' at the end, so we 
 * need to be carefull about indexes (inStart, inEnd, postStart, postEnd)
 */
Node* construct_tree_post_and_in(vector<int> &in, int inStart, int inEnd, vector<int> &post, int postStart, int postEnd, map<int, int> inMap) {
    if(inStart > inEnd || postStart > postEnd)
        return nullptr;
    
    // Process
    // 1. Create the root node
    Node* root = new Node(post[postEnd]);

    // 2. Identify root's index in in-order
    int rootIdx = inMap[root->data];
    int leftRange = rootIdx - inStart;

    // Recursive calls
    root->left = construct_tree_post_and_in(in, inStart, rootIdx - 1, post, postStart, postStart + leftRange - 1, inMap);
    root->right = construct_tree_post_and_in(in, rootIdx + 1, inEnd, post, postStart + leftRange, postEnd - 1, inMap);
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

    // Construct tree using 'pre' and 'in' order traverse sequences.
    Node* resultTree = construct_tree_pre_and_in(in, 0, in.size() - 1, pre, 0, pre.size() - 1, inMap);
    cout << "Printing result in pre-order for 'pre' and 'in' input: " << endl;
    print_pre_order(resultTree);

    // Construct tree using 'post' and 'in' order traverse sequences.
    vector<int> post = {40,50,20,60,30,10};
    Node* resultTree2 = construct_tree_post_and_in(in, 0, in.size() - 1, post, 0, post.size() - 1, inMap);
    cout << "\nPrinting result in pre-order for 'post' and 'in' input: " << endl;
    print_pre_order(resultTree2);

    return 0;
}