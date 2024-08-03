#include <iostream>
#include <stack>
#include "ll_utility.h"

using namespace std;

/**
 * Approach: Brute-force
 * Uses 'Stack' to store visited nodes and do another traverse to match node's value.
 */
bool check_palindrome_brute_force(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp) {
        int val = st.top();
        if(val != temp->data)
            return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

Node* reverse_ll(Node* node) {
    Node* temp = node;
    Node* front = nullptr;
    Node* prev = nullptr;

    while(temp) {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

/**
 * Approach: Optimal
 * 1. Get LL length and find the mid-point of linked-list
 * 2. Reverse the links for 2nd half and keep one pointer at the end of LL.
 * 3. Keep another pointer at start of 1st half of LL and start matching 'start' and 'end' poniters.
 * 4. Move 'start' forward and 'end' backward (due to reversed links of 2nd half)
 */
bool check_palindrome_optimal(Node* head) {
    // Step-1: Reach mid-point of LL
    Node* slow = head;
    Node* fast = head;

    while(fast->next && fast->next->next) { // TC: O(N/2)
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step-2: Reverse 2nd half of LL
    Node* head2 = reverse_ll(slow->next); // TC: O(N/2)

    // Step-3: Compare nodes in 1st and 2nd halves
    Node* first = head;
    Node* second = head2;
    while(second) { // TC: O(N/2)
        if(first->data != second->data) {
            // reverse 2nd half back to original structure
            reverse_ll(head2);  // TC: O(N/2)
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse_ll(head2); // TC: O(N/2)
    return true;
}

int main() {
    vector<int> arr = {1,2,3,3,2,1};
    Node* head = arrToLL(arr);
    print_linked_list(head); // IMPORTANT: Don't print after adding loop.

    cout << "\nIs Palindrome? (Brute-force):\n" << (check_palindrome_brute_force(head) ? "YES" : "NO");
    cout << "\nIs Palindrome? (Optimal):\n" << (check_palindrome_optimal(head) ? "YES" : "NO");

    return 0;
}