/**
 * Given a linked list where every node has 'next' and 'random' pointer. Clone this linked list.
 * YouTube(Striver's): https://www.youtube.com/watch?v=q570bKdrnlw
 */

#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* random;

        Node(int _data) {
            data = _data;
            next = nullptr;
            random = nullptr;
        }
};

void print_linked_list_with_random(Node* head) {
    if(!head) {
        cout << "<empty>" << endl;
        return;
    }
    
    Node* temp = head;
    while(temp) {
        cout << temp->data << "(" << temp->random->data << ")" << " -> ";
        temp = temp->next;
    }
}

/**
 * Approach: Brute-force (Using hashmap for storing Original -> Cloned node)
 * 1. Create a copy node for every original node (with its data). Store them in hashmap against original node.
 * 2. Traverse through Hashmap to link 'random' and 'next' pointer by using original's node's reference.
 */
Node* clone_linked_list_brute(Node* head) {
    
}

/**
 * Approach: Optimal
 * 1. Create copy node and insert after original node.
 * 2. Connect Random pointers.
 * 3. Connect Next pointers.
 * 
 * TC: O(3N) for 3 iterations
 * SC: O(1), no extra space used
 */
Node* clone_linked_list_optimal(Node* head) {
    // step-1: Create Copy node from original node and insert between original nodes
    Node* temp = head;
    while(temp) {
        Node* copy = new Node(temp->data);
        copy->next = temp->next;
        temp->next = copy;

        temp = temp->next->next;
    }

    // step-2: Connect random pointer
    temp = head;
    while(temp) {
        Node* copyNode = temp->next;
        if(temp->random) {
            copyNode->random = temp->random->next;
        } else {
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }

    // step-3: Connect next pointer (extract the copies list)
    temp = head;
    Node* dummy = new Node(-1);
    Node* mover = dummy;
    while(temp) {
        Node* copyNode = temp->next;
        mover->next = copyNode;
        temp->next = copyNode->next;

        temp = temp->next;
        mover = copyNode;
    }

    return dummy->next;
}



int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    print_linked_list_with_random(head);

    // Node* result = clone_linked_list_brute(head);
    // print_linked_list_with_random(result);

    Node* result2 = clone_linked_list_optimal(head);
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    print_linked_list_with_random(result2);
    return 0;
}