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

Node* search_bst(Node* root, int ele) {
    if(root == nullptr || root->data == ele)
        return root;
    if(ele < root->data)
        return search_bst(root->left, ele);
    else
        return search_bst(root->right, ele);
}

int main() {
    // BST
    Node* root = new Node(5);
    root->left = new Node(3);
        root->left->left = new Node(1);
        root->left->right = new Node(4);
    root->right = new Node(8);
        root->right->right = new Node(10);
        root->right->right->left = new Node(9);

    Node* resultNode = search_bst(root, 4);
    if(resultNode)
        cout << "Result: " << resultNode->data;
    else
        cout << "Not found!";
    
    return 0;
}