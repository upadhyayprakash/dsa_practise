/**
 * YouTube (Striver's): https://www.youtube.com/watch?v=wiOo4DC5GGA
 */

#include <iostream>
#include <unordered_map>
#include "utility.h"

using namespace std;

Node* add_a_loop(Node* head) {
    Node* temp = head;
    Node* memory = nullptr;
    int pos = 5;
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
 * 1. Store the visited nodes in a map
 * 2. While inserting a new node, check if already present.
 * 3. If Yes, there's a loop, return `true`
 * 4. If No, continue till end of linked list and return false.
 */
bool is_loop_brute_force(Node* head) { // Time Complexity: O(N * LogN), Space Complexity: O(N)
    Node* temp = head;
    unordered_map<Node*, int> mpp;
    while(temp) {
        if(mpp.find(temp) == mpp.end()) // Node not present in map
            mpp[temp] = 1;
        else
            return true;
        temp = temp->next;
    }
    return false;
}

/**
 * Approach: Tortoise & Hare Algo (Slow and Fast Pointers)
 * 1. 'slow' pointer moves 1-step and 'fast' moves 2-steps.
 * 2. If there's no loop, the traversal will finish and 'fast' will reach end
 * of linked-list sooner than 'slow' pointer.
 * 3. If there's LOOP, the traversal won't finish, but there'll be moment when slow
 * and fast will meet and hence, there's a loop.
 */
bool is_loop_optimal(Node* head) { // TC: O(N), SC(1)
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head = arrToLL(arr);
    printLL(head); // IMPORTANT: Don't print after adding loop.
    head = add_a_loop(head);
    cout << "\nIs Loop?\n" << (is_loop_brute_force(head) ? "YES" : "NO");
    cout << "\nIs Loop?\n" << (is_loop_optimal(head) ? "YES" : "NO");
    return 0;
}