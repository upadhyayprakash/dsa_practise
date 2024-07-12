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

vector<vector<int>> zig_zag_traversal(Node* root) {
    vector<vector<int>> result;
    if(root == nullptr)
        return result;
    
    queue<Node*> q;
    q.push(root);
    bool flag = true; // for 'left-to-right' traversal
    while(!q.empty()) {
        int qSize = q.size();
        vector<int> levelElements(qSize);
        for(int i = 0; i < qSize; i++) {
            Node* node = q.front();
            q.pop();

            int idx = flag ? i : (qSize -1 - i);
            levelElements[idx] = node->data;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        flag = !flag;
        result.push_back(levelElements);
    }

    return result;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    vector<vector<int>> result = zig_zag_traversal(root);
    cout << "Zig-zag traversal:\n";
    for(auto i: result) {
        for(auto j: i) {
            cout << j << " ";
        }
    }

    return 0;
}