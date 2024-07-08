#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    public:
    Node(int data1, Node *next1) {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* arrToLL(vector<int> &arr) {
    if(arr.size() == 0) return (Node*)nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print_linked_list(Node* head) {
    if(!head)
        cout << "<empty>" << endl;
    
    Node* temp = head;
    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int get_length_linked_list(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

bool search_ele_in_linked_list(Node* head, int ele) {
    Node* temp = head;

    while(temp) {
        if(temp->data == ele)
            return true;
        temp = temp->next;
    }
    return false;
}

Node* delete_head(Node* head) {
    if(head == nullptr) {
        cout << "Can't delete, <empty> list" << endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp; // free the memory of last 'head'
    }
    return head;
}

Node* delete_tail(Node* head) {
    if(head == nullptr) {
        cout << "Can't delete, <empty> list" << endl;
        return head;
    }
    
    if(head->next == nullptr)
    {
        head = nullptr;
        return head;
    } 

    Node* temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    
    return head;
}

Node* delete_position(Node* head, int pos) {
    if(head == nullptr) {
        cout << "Can't delete, <empty> list" << endl;
        return head;
    }
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!= nullptr) {
        cnt++;
        if(cnt == pos) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* delete_by_value(Node* head, int value) {
    if(head == nullptr) {
        cout << "Can't delete, <empty> list" << endl;
        return head;
    } 
    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    
    while(temp->next) {
        if(temp->next->data == value)
            break;
        temp = temp->next;
    }
    if(temp->next)
        temp->next = temp->next->next;
    return head;
}

int main() {
    vector<int> arr = {};
    Node* head = arrToLL(arr);
    if(head)
        cout << "Head data: " << head->data << endl;
    else
        cout << "<empty>" << endl;

    /* Traverse the LinkedList */
    cout << "\nPrint LinkedList: " << endl;
    print_linked_list(head);

    /* Find length of a Linked List */
    cout << endl << "Length: " << get_length_linked_list(head) << endl;

    /* Search element in LinkedList */
    int ele = 3;
    cout << endl << "Element " << ele << " exist? " << search_ele_in_linked_list(head, ele);

    /* Deletion in LinkedList */
    cout << "\nDelete head:\n";
    head = delete_head(head);
    print_linked_list(head);

    cout << "\nDelete tail:\n";
    head = delete_tail(head);
    print_linked_list(head);

    int pos = 4;
    cout << "\nDelete at Position " << pos << ":\n";
    head = delete_position(head, pos);
    print_linked_list(head);
    
    
    int value = 8;
    cout << "\nDelete by value " << value << ":\n";
    head = delete_by_value(head, value);
    print_linked_list(head);
    


    /* Insertion in LinkedList */

    return 0;
}