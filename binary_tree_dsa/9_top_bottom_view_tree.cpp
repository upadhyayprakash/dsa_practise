#include <iostream>
#include <map>
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

vector<int> top_view(Node* root) {
    vector<int> result;
    if(root == nullptr)
        return result;
    
    queue<pair<Node*, int>> q;
    map<int, int> mp;

    q.push({root, 0});
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        q.pop();
        
        Node* node = p.first;
        int vertical = p.second;
        
        if(!mp.count(vertical))
            mp[vertical] = node->data;

        if(node->left) q.push({node->left, vertical - 1});
        if(node->right) q.push({node->right, vertical + 1});
    }
    for(auto i: mp)
        result.push_back(i.second);
    return result;
}

vector<int> bottom_view(Node* root) {
    vector<int> result;
    if(root == nullptr)
        return result;
    
    queue<pair<Node*, int>> q;
    map<int, int> mp;

    q.push({root, 0});
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        q.pop();
        
        Node* node = p.first;
        int vertical = p.second;
        
        mp[vertical] = node->data;

        if(node->left) q.push({node->left, vertical - 1});
        if(node->right) q.push({node->right, vertical + 1});
    }
    for(auto i: mp)
        result.push_back(i.second);
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> top_result = top_view(root);
    cout << "Top view of tree:\n";
    for(auto i: top_result) {
        cout << i << " ";
    }
    vector<int> bottom_result = bottom_view(root);
    cout << "\n\nBottom view of tree:\n";
    for(auto i: bottom_result) {
        cout << i << " ";
    }
    return 0;
}