#include <iostream>
#include "0_linked_list_library.h"
using namespace std;

Node* get_middle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    if(!head) return nullptr;

    while(fast->next) {
        fast = fast->next;
        if(fast->next)
            fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = arrToLL(arr);
    
    cout << "Print LinkedList: " << endl;
    print_linked_list(head);

    Node* result = get_middle(head);
    if(result)
        cout << "\nMiddle ele:\n" << result->data;
    else
        cout << "\nMiddle ele:\n-1";
    
    return 0;
}