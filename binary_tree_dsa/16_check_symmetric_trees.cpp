#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int _data) {
            data = _data;
            left = right = nullptr;
        }
};

void render_tree(Node* node, string prefix = "", bool isLast = true)
{
    if( node != nullptr )
    {
        cout << prefix;
        cout << (!isLast ? "├──" : "└──" );
        cout << " "  << node->data << endl;

        render_tree(node->left, prefix + (!isLast ? "│   " : "    "), false);
        render_tree(node->right, prefix + (!isLast ? "│   " : "    "), true);
    }
}

bool is_symmetric(Node* root1, Node* root2) {
    // Base Condition
    if(root1 == nullptr || root2 == nullptr)
        return root1 == root2;
    
    // Process: Compare node's data
    return root1->data == root2->data
        && is_symmetric(root1->left, root2->right)
        && is_symmetric(root1->right, root2->left);
}

int main() {
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(1);
    root->left->left = new Node(2);
    root->right->right = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(3);
    root->left->left->left = new Node(4);
    root->right->right->right = new Node(4);
    render_tree(root);

    cout << "Is symmetric:\n" << (is_symmetric(root->left, root->right) ? "YES" : "NO");
    return 0;
}