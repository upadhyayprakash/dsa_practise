#include <iostream>
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

// Used for printing result of flattened tree
void print_pre_order(Node* root) {
    if(root == nullptr)
        return;
    
    cout << root->data << " ";
    print_pre_order(root->left);
    print_pre_order(root->right);
}

void flatten_tree(Node* root, Node* &prev) {
    if(root == nullptr)
        return;
    
    flatten_tree(root->right, prev);
    flatten_tree(root->left, prev);

    root->right = prev;
    root->left = nullptr;
    prev = root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
        root->left->left = new Node(3);
        root->left->right = new Node(4);
    root->right = new Node(5);
        root->right->right = new Node(6);
        root->right->right->left = new Node(7);

    Node* prev = nullptr; // used to track 'prev' Node
    flatten_tree(root, prev);
    print_pre_order(root);
    
    return 0;
}