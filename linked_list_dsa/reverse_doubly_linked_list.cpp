#include <iostream>
#include "dll_utility.h"
using namespace std;


Node* reverse_doubly_linked_list(Node* head) {
    if(head == nullptr || !head->next)
        return head;
    
    Node* last = nullptr;
    Node* current = head;

    while(current) {
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }

    return last->back;
}

int main() {
    vector<int> arr = {1,2,3,4,5};

    /* Array to Doubly Linked List */
    Node* head = arrToDLL(arr);
    cout << "Doubly Linked List" << endl;
    printDLL(head);

    /* Reverse the Doubly Linked List */
    cout << "\nReversed List:" << endl;
    head = reverse_doubly_linked_list(head);
    printDLL(head);

    return 0;
}