/**
 * Sort K sorted array.
 */
#include <iostream>
#include <queue>
using namespace std;

class Node { // creating class object to store element's position in 2D array
    public:
        int value;
        int i;
        int j;
    
    Node(int _value, int _i, int _j) {
        value = _value;
        i = _i;
        j = _j;
    }
};

class CompareClass {
    public:
    bool operator() (Node* &node1, Node* &node2) { // operator overloading
        return node1->value > node2->value;
    }
};

vector<int> sort_k_sorted_array(vector<vector<int>> arr, int k) {
    priority_queue<Node*, vector<Node*>, CompareClass> pqMin; // with custom comparator
    for(int i = 0; i < k; i++) {
        pqMin.push(new Node(arr[i][0], i, 0));
    }

    vector<int> result;
    while(!pqMin.empty()) {
        // Get the top PQ element (minimum)
        Node* top = pqMin.top();
        pqMin.pop();
        result.push_back(top->value);

        int i = top->i;
        int j = top->j;

        if(j < k - 1)
            pqMin.push(new Node(arr[i][j+1], i, j+1));
    }
    return result;
}

int main() {
    vector<vector<int>> arr = {{10,20,30},{4,5,6}, {7,8,9}};
    int k = arr.size();
    vector<int> result = sort_k_sorted_array(arr, k);
    cout << "Sorted arrays:\n";
    for(auto i: result) {
        cout << i << " ";
    }
    return 0;
}