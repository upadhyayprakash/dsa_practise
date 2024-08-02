/**
 * Find start node of 'Loop' in linked list
 * YouTube (Striver's): https://www.youtube.com/watch?v=2Kd0KKmmHFc
 */
#include <iostream>
#include "utility.h"
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
 * Approach: Brute-force
 * 1. Store each node in hashmap while parsing the linkedlist
 * 2. If a node appears again, return that node.
 * 
 * Time Complexity: O(N * LogN) --> 'LogN' for 2 hashmap operations (insert and find)
 * Space Complexity: O(N)
 */

/**
 * Approach: Optimal
 * 1. Step-1: detecting the loop (check when 'slow' and 'fast' collide)
 * 2. Step-2: Take 'slow' pointer to LL 'head' and move both 'slow' and 'fast' one step.
 * 3. If they collide "again", that's our starting point of the loop. How??
 */

Node* get_start_of_loop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool is_loop_present = false;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            is_loop_present = true;
            break;
        }
    }
    if(is_loop_present) {
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    } else
        return nullptr;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = arrToLL(arr);
    printLL(head); // IMPORTANT: Don't print after adding loop.
    head = add_a_loop(head);

    Node* result = get_start_of_loop(head);
    int val = result ? result->data : 0;
    cout << "\nStart point of Loop:\n" << val;
    return 0;
}