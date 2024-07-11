// YouTube: https://youtu.be/Rezetez59Nk?si=rCy6i6VWYEWSeHZx
#include <iostream>
#include <algorithm>
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

int get_tree_diameter(Node* node, int &diameter) {
    if (!node) {
        return 0;
    }

    int lh = get_tree_diameter(node->left, diameter);
    int rh = get_tree_diameter(node->right, diameter);

    // Update the diameter with the maximum
    // of current diameter or sum of
    // left and right heights

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
        root->right->left = new Node(4);
            root->right->left->left = new Node(5);
                root->right->left->left->left = new Node(9);
        root->right->right = new Node(6);
            root->right->right->right = new Node(7);
                root->right->right->right->right = new Node(8);

    int diameter = 0;
    int result = get_tree_diameter(root, diameter); // 'result' not to use.
    cout << "Diameter: " << diameter << endl; // 'diameter' has the result.

    return 0;
}