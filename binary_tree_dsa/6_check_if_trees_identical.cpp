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

bool check_identicals(Node* root1, Node* root2) {
    if(root1 == nullptr || root2 == nullptr)
        return root1 == root2;
    
    return (root1->data == root2->data)
    && check_identicals(root1->left, root2->left)
    && check_identicals(root1->right, root2->right);
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(5);
    root1->right->right = new Node(7);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->right = new Node(5);
    root2->right->right = new Node(7);

    cout << "Identical?" << endl << check_identicals(root1, root2);

    return 0;
}