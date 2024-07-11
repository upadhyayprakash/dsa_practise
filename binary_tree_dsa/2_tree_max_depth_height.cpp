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

int tree_depth(Node* root) {
    if(root == nullptr)
        return 0;
    
    return 1 + max(tree_depth(root->left), tree_depth(root->right));
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);

    cout << "Tree Height: " << tree_depth(root) << endl;

    return 0;
}