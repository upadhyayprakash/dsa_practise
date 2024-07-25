#include <iostream>
#include <stack>
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

void print_iterative_inorder(Node* root) {
    stack<Node*> st;
    Node* node = root;

    while(true) {
        if(node) {
            st.push(node);
            node = node->left;
        } else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    render_tree(root);

    cout << "\nIterative In-order:\n";
    print_iterative_inorder(root);
    
    return 0;
}