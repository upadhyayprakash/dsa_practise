/**
 * YouTube (Striver's): https://www.youtube.com/watch?v=0DYoPz2Tpt4
 */

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int _data) {
            data = _data;
            next = nullptr;
        }

        Node(int _data, Node* _next) {
            data = _data;
            next = _next;
        }
};

void print_ll(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

Node* get_intersecting_node(Node* headA, Node* headB) { // Time Complexity: O(N1 + N2)
    if(headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    Node* tempA = headA;
    Node* tempB = headB;

    while(tempA !=  tempB) { // Run till they're not same
        tempA = tempA->next;
        tempB = tempB->next;

        if(tempA == tempB) return tempA; // this will ensure the loop exists when both are at the end.

        if(tempA == nullptr)
            tempA = headB;
        if(tempB == nullptr)
            tempB = headA;
    }
    return tempA;
}

int main() {
    Node* node4 = new Node(4, new Node(6, new Node(2)));
    Node* headA = new Node(3, new Node(1, node4));
    Node* headB = new Node(1, new Node(2, new Node(4, new Node(5, node4))));
    cout << "headA:\n";
    print_ll(headA);
    cout << "headB:\n";
    print_ll(headB);

    cout << "\nIntersecting Node:\n";
    cout << get_intersecting_node(headA, headB)->data;

    return 0;
}