#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* back;
    
    public:
        Node(int data1, Node* next1, Node* back1) {
            data = data1;
            next = next1;
            back = back1;
        }

    public:
        Node(int data1) {
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* arrToDLL(vector<int> &arr) {
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printDLL(Node* head) {
    if(head == nullptr) {
        cout << "<empty>" << endl;
        return;
    }
    
    Node* temp = head;

    while(temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

}