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

int check_balanced_tree(Node* root) {
    if(root == nullptr) return 0;

    int lh = check_balanced_tree(root->left);
    int rh = check_balanced_tree(root->right);

    if(lh == -1 || rh == -1) return -1; // check if any subtree returned -1
    if(abs(lh - rh) > 1) return -1; // check if subtree height diff is more than 1
    
    return 1 + max(lh, rh);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
        root->left->left = new Node(10);
            root->left->left->left = new Node(101);
            root->left->left->right = new Node(100);
    
        root->left->right = new Node(22);
                root->left->right->left = new Node(220);
                root->left->right->right = new Node(221);
    root->right = new Node(3);
        root->right->left = new Node(4);
            root->right->left->left = new Node(5);
                root->right->left->left->right = new Node(55);
            root->right->left->right = new Node(404);
        root->right->right = new Node(606);
            root->right->right->left = new Node(66);
            root->right->right->right = new Node(67);
    
    

    cout << "Is tree balanced?" << endl;
    cout << check_balanced_tree(root);
}