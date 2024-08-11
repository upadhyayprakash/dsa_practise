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

/**
 * Approach:
 * 1. For a given node, calculate the (leftMaxPath + rightMaxPath + node->val).
 * 2. Store the maxSum till now in some global variable.
 */
int max_sum_path(Node* root, int &maxSum) {
    if(root == nullptr) return 0;

    int lMaxSum = max(0, max_sum_path(root->left, maxSum)); // '0' should be minimum if not choosing the path
    int rMaxSum = max(0, max_sum_path(root->right, maxSum));
    int data = root->data;

    int total = lMaxSum + rMaxSum + data;
    maxSum = max(maxSum, total);
    return data + max(lMaxSum, rMaxSum); // This is not the final Result
}

int main() {
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(1);

    int maxSum = INT_MIN; // important for negative answers eg. tree with only node [-3]
    max_sum_path(root, maxSum);
    cout << "Max sum path value: " << endl << maxSum;
    return 0;
}