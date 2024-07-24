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

int main() {
    // construct a linked list
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = arrToLL(arr);

    cout << "Original Linked List:\n";
    print_linked_list(head);

    cout << "\n\nReversed Linked List:\n";
    Node* result = reverse_linked_list(head);
    print_linked_list(result);
    return 0;
}