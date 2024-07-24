/* Doubly Linked List */
#include <iostream>
#include "dll_utility.h"
using namespace std;

Node* delete_head(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    
    return head;
}

Node* delete_tail(Node* head) {
    if(head == nullptr) {
        return head;
    }

    if(!head->next) { // only 'head' present
        return nullptr;
    }

    Node* temp = head;

    while(temp->next) {
        temp = temp->next;
    }

    // Node* tail = temp;
    temp->back->next = temp->next;
    temp->back = nullptr;
    delete temp;
    
    return head;
}

Node* delete_position(Node* head, int pos) {
    if(head == nullptr) {
        cout << "Can't delete, <empty> list" << endl;
        return nullptr;
    }

    if(!head->next)
        return nullptr;

    if(pos == 1) { // only 'head' present
        Node* temp = head;
        head = temp->next;
        head->back = nullptr;
        temp->next = nullptr;
        return head;
    }

    Node* temp = head;
    while(temp && --pos) {
        temp = temp->next;
    }

    temp->back->next = temp->next;
    temp->next->back = temp->back;
    temp->next = temp->back = nullptr;
    delete temp;

    return head;
}

int main() {
    vector<int> arr = {1,2,3,4};

    /* Array to Doubly Linked List */
    Node* head = arrToDLL(arr);
    cout << "Doubly Linked List" << endl;
    printDLL(head);

    /* Deletion of Doubly Linked List */
    cout << "\nDelete head:" << endl;
    head = delete_head(head);
    printDLL(head);

    cout << "\nDelete tail:" << endl;
    head = delete_tail(head);
    printDLL(head);

    cout << "\nDelete position:" << endl;
    int pos = 1;
    head = delete_position(head, pos);
    printDLL(head);

    /* Insertion of Doubly Linked List */
    // ToDo

    return 0;
}