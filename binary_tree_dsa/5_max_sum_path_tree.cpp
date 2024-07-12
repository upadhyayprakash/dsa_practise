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

int max_sum_path(Node* root, int &maxSum) {
    if(root == nullptr) return 0;

    int lMaxSum = max_sum_path(root->left, maxSum);
    int rMaxSum = max_sum_path(root->right, maxSum);
    int data = root->data;

    int total = lMaxSum + rMaxSum + data;
    maxSum = max(maxSum, total);
    return data + max(lMaxSum, rMaxSum);
}

int main() {
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(1);

    int maxSum = 0;
    max_sum_path(root, maxSum);
    cout << "Max sum path value: " << endl << maxSum;
    return 0;
}