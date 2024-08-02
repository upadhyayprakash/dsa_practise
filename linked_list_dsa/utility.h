#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
    public:
        Node(int _data, Node* _next) {
            data = _data;
            next = _next;
        }

    public:
        Node(int _data) {
            data = _data;
            next = nullptr;
        }
};

Node* arrToLL(vector<int> &arr) {
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    return head;
}

void printLL(Node* head) {
    if(head == nullptr) {
        cout << "<empty>" << endl;
        return;
    }
    
    Node* temp = head;

    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}
