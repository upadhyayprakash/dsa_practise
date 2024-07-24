#include <iostream>
#include "0_linked_list_library.h"
using namespace std;

Node* reverse_linked_list(Node* head) {
    Node* mover = head;
    Node* front = nullptr;
    Node* prev = nullptr;

    while(mover) {
        front = mover->next;
        mover->next = prev;
        prev = mover;
        mover = front;
    }

    return prev;
}

Node* reverse_linked_list_recursive(Node* head) {
    // Base Condition
    if(!head || !head->next)
        return head;
    
    // Recursive Call
    Node* newHead = reverse_linked_list_recursive(head->next);

    // Process: Swap the nodes
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

int main() {
    // construct a linked list
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = arrToLL(arr);

    cout << "Original Linked List:\n";
    print_linked_list(head);

    cout << "\n\nReversed Linked List (iterative):\n";
    Node* result = reverse_linked_list(head);
    print_linked_list(result);

    cout << "\n\nReversed Linked List (recursive):\n";
    Node* head1 = arrToLL(arr);
    Node* result1 = reverse_linked_list_recursive(head1);
    print_linked_list(result1);

    return 0;
}