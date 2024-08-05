/**
 * Group Odd and Even nodes together in a Linked list.
 * YouTube (Striver's): https://www.youtube.com/watch?v=qf6qp7GzD5Q
 */

#include <iostream>
#include "ll_utility.h"

using namespace std;

/**
 * Approach: Brute-force
 * 1. Create a vector<int> to store LL's node values.
 * 2. Parse Odd nodes by jumping 2 places and store values in list.
 * 3. Parse Even nodes (starting from 2nd node) and store every 2nd node's value.
 * 4. Now, use the list to replace LL's values from start till end.
 * 
 * TC: O(2N), SC: O(N)
 */

/**
 * Approach: Optimal
 * 1. Chain the Odd nodes together
 * 2. Chain the Even nodes together
 * 3. Link end of Odd chain with start of Even chain.
 */
Node* group_odd_even_nodes(Node* head) { // TC: O(N), SC(1)
    // TODO: Arrange Odd nodes first, and then Even nodes.
    if(!head || !head->next) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next; // for step-3: link end of 'odd' chain with start of 'even' chain.

    while(even && even->next) {
        odd->next = odd->next->next; // link to next 'odd' node
        odd = odd->next;
        even->next = even->next->next; // link to next 'even' node
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head = arrToLL(arr);
    print_linked_list(head);

    Node* newHead = group_odd_even_nodes(head);
    cout << "\nGrouped LL:\n";
    print_linked_list(newHead);
    
    return 0;
}