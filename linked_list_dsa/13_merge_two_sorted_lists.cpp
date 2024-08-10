#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int _data) {
            data = _data;
            next = nullptr;
        }

        Node(int _data, Node* _next) {
            data = _data;
            next = _next;
        }
};

/**
 * TC: O(m + n)
 * SC: O(m + n), Auxiliary stack space.
 */
Node* mergeTwoList_recursive(Node* list1, Node* list2) {
    if(!list1) return list2;
    if(!list2) return list1;

    if(list1->data <= list2->data) {
        list1->next = mergeTwoList_recursive(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoList_recursive(list1, list2->next);
        return list2;
    }
}

/**
 * TC: O(m + n)
 * SC: O(1)
 */
Node* mergeTwoList_iterative(Node* list1, Node* list2) {
    Node* head = new Node(0);
    Node* temp = head;
    while(list1 && list2) {
        if(list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next; // point 'temp' to newly added node.
    }

    temp->next = list1 ? list1 : list2;
    return head->next;
}

int main() {
    Node* head1 = new Node(1, new Node(2, new Node(3)));
    Node* head2 = new Node(4, new Node(5, new Node(6)));
    
    Node* result = mergeTwoList_recursive(head1, head2);
    cout << "Merge sorted list:(recursive)\n";
    Node* temp = result;
    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    head1 = new Node(1, new Node(2, new Node(3)));
    head2 = new Node(4, new Node(5, new Node(6)));
    Node* result2 = mergeTwoList_iterative(head1, head2);
    cout << "\nMerge sorted list:(iterative)\n";
    temp = result2;
    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    return 0;
}