#include <iostream>
#include <queue>
#include <stack>
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
    
    print_in_order(root->left);
    cout << root->data << " ";
    print_in_order(root->right);
}

void print_post_order(Node* root) {
    if(root == nullptr)
        return;
    
    print_post_order(root->left);
    print_post_order(root->right);
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

void print_pre_in_post_order_at_once(Node* root) {
    vector<int> pre, in, post;
    stack<pair<Node*, int>> st;
    st.push({root, 1});

    if(root == nullptr) return;

    while(!st.empty()) { // loop till stack has any Node
        pair<Node*, int> item = st.top();
        st.pop();
        if(item.second == 1) {
            pre.push_back(item.first->data); // insert in 'pre' list
            item.second++; // increment counter
            st.push(item); // push item itself
            if(item.first->left) st.push({item.first->left, 1}); // push item's left child
        }
        else if(item.second == 2) {
            in.push_back(item.first->data); // insert in 'in' list
            item.second++; // increment counter
            st.push(item); // push item itself
            if(item.first->right) st.push({item.first->right, 1}); // push item's left child
        } else {
            post.push_back(item.first->data); // insert in 'post' list
        }
    }

    cout << "\nPreorder:\n";
    for(auto i: pre) {
        cout << i << " ";
    }
    cout << "\nInorder:\n";
    for(auto i: in) {
        cout << i << " ";
    }
    cout << "\nPostorder:\n";
    for(auto i: post) {
        cout << i << " ";
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

    cout << "\nPre-order:\n";
    print_pre_order(root);
    cout << endl;
    cout << "\nIn-order:\n";
    print_in_order(root);
    cout << endl;
    cout << "\nPost-order:\n";
    print_post_order(root);
    cout << endl;
    cout << "\nLevel-order:\n";
    print_level_order(root);
    cout << endl;
    print_pre_in_post_order_at_once(root);

    return 0;
}