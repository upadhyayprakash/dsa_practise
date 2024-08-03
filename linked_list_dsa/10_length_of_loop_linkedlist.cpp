#include <iostream>
#include "ll_utility.h"

using namespace std;

Node* add_a_loop(Node* head) {
    Node* temp = head;
    Node* memory = nullptr;
    int pos = 3;
    while(temp->next) {
        temp = temp->next;
        pos--;
        if(pos == 1) memory = temp;
    }
    temp->next = memory;
    cout << "\nAdded loop from end to node:\n" << memory->data << endl;
    return head;
}

/**
 * Approach:
 * 1. Find loop point and keep one pointer at a collision point.
 * 2. Move the other pointer 1-step with a counter until it meets previous pointer.
 */

int get_loop_length(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            slow = slow->next;
            int count = 1;
            while(slow != fast) {
                slow = slow->next;
                count++;
            }
            return count;
        }
    }
    return 0;
}


int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = arrToLL(arr);
    print_linked_list(head); // IMPORTANT: Don't print after adding loop.
    head = add_a_loop(head);

    cout << "\nLength of Loop:\n" << get_loop_length(head);

    return 0;
}