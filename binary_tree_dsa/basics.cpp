#include <iostream>
#include <queue>
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

void print_pre_order(Node* root) {
    if(root == nullptr)
        return;
    
    cout << root->data << " ";
    print_pre_order(root->left);
    print_pre_order(root->right);
}

void print_in_order(Node* root) {
    if(root == nullptr)
        return;
    
    print_pre_order(root->left);
    cout << root->data << " ";
    print_pre_order(root->right);
}

void print_post_order(Node* root) {
    if(root == nullptr)
        return;
    
    print_pre_order(root->left);
    print_pre_order(root->right);
    cout << root->data << " ";
}

void print_level_order(Node* root) {
    if(root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    print_pre_order(root);
    cout << endl;
    print_in_order(root);
    cout << endl;
    print_post_order(root);
    cout << endl;
    print_level_order(root);
    return 0;
}