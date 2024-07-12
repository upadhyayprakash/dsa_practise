#include <iostream>
#include <queue>
#include <string>
#include <sstream>

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

// Used for printing result of deserialized tree
void print_pre_order(Node* root) {
    if(root == nullptr)
        return;
    
    cout << root->data << " ";
    print_pre_order(root->left);
    print_pre_order(root->right);
}

string serialize_tree(Node* root) {
    // we'll use level-order traversal and mark null nodes as '#' for easy deserailization
    if(root == nullptr)
        return "";
    
    string result;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        if(node == nullptr)
            result.append("#,");
        else
            result.append(to_string(node->data)+',');
        
        if(node) {
            q.push(node->left);
            q.push(node->right);
        }
    }

    return result;
}

Node* deserialize_tree(string seq) {
    if(seq.size() == 0) return nullptr;

    stringstream s(seq);

    string str;
    getline(s, str, ',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;

    q.push(root);
    
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == '#')
            node->left = nullptr;
        else {
            Node* leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == '#')
            node->right = nullptr;
        else {
            Node* rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(13);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string treeStr = serialize_tree(root);
    cout << "Serialized tree: \n" << treeStr << endl;

    cout << "Deserialized tree:\n";
    Node* result = deserialize_tree(treeStr);
    print_pre_order(result);
}