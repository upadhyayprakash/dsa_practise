#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int val;
        vector<Node*> neighbors;

        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
};

int main() {
    Node* first = new Node(1);
    Node* n2 = new Node(2);
    n2->neighbors.push_back(first);
    first->neighbors.push_back(n2);

    vector<Node*> visited(2, nullptr);
    Node* copy = new Node(first->val);
    visited[first->val] = copy;

    queue<Node*> q;
    q.push(first);

    while(!q.empty()) {
        Node* node = q.front();
        q.pop();

        
        for(int i = 0; i < node->neighbors.size(); i++) {
            if(visited[node->neighbors[i]] == nullptr) {
                visited[]
            }
        }
    }

    return 0;
}