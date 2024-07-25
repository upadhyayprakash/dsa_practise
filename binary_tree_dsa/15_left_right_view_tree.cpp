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

void get_right_view(Node* root, int level, vector<int> &res) {
    // Using Reverse "Pre-order" traversal -> Root - Right - Left
    if(!root)
        return;
    
    if(level == res.size()) { // first node of a 'level'
        res.push_back(root->data);
    }

    get_right_view(root->right, level + 1, res);
    get_right_view(root->left, level + 1, res);
}

void get_left_view(Node* root, int level, vector<int> &res) {
    // Using "Pre-order" traversal -> Root - Left - Right
    if(!root)
        return;
    
    if(level == res.size()) { // first node of a 'level'
        res.push_back(root->data);
    }

    get_left_view(root->left, level + 1, res);
    get_left_view(root->right, level + 1, res);
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

    vector<int> res;
    get_right_view(root, 0, res); // (Node* root, int level, vector<int> &res)
    cout << "Right view:\n";
    for(auto i: res) {
        cout << i << " ";
    }

    vector<int> res1;
    get_left_view(root, 0, res1); // (Node* root, int level, vector<int> &res)
    cout << "\nLeft view:\n";
    for(auto i: res1) {
        cout << i << " ";
    }
    return 0;
}