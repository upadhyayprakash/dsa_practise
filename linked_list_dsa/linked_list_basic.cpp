/* Linked List */
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
    if(arr.size() == 0) return nullptr;

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
    if(!head) {
        cout << "<empty>" << endl;
        return;
    }
    
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
    cout << "\nLength: " << count << endl;
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

Node* insert_head(Node* head, int ele) {
    Node* newNode = new Node(ele);

    Node* temp = head;
    newNode->next = temp;
    head = newNode;
    return head;
}

Node* insert_tail(Node* head, int ele) {
    Node* newNode = new Node(ele);

    if(head == nullptr) {
        head = newNode;
        return head;
    }

    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

Node* insert_position(Node* head, int ele, int pos) {
    if(pos < 1 || pos > (get_length_linked_list(head) + 1)) {
        cout << "\nCan't insert at given position: " << pos << endl;
        return head;
    }
    Node* newNode = new Node(ele);

    if(pos == 1 || head == nullptr) {
        Node* temp = head;
        newNode->next = temp;
        head = newNode;
        return head;
    }

    int count = 1;
    Node* temp = head;
    while(temp) {
        count++;
        if(count == pos) {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

Node* insert_before_value(Node* head, int ele, int value) {
    if(head == nullptr) { // LL is empty
        return head;
    }
    if(head->data == value) { // target 'value' is at the 'head'
        return new Node(ele, head);
    }

    Node* temp = head;
    while(temp->next) {
        if(temp->next->data == value) {
            // insert after temp
            temp->next = new Node(ele, temp->next); // constructor with next pointer
            break;
        }
        temp = temp->next;
    }

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

    int pos = 2;
    cout << "\nDelete at Position " << pos << ":\n";
    head = delete_position(head, pos);
    print_linked_list(head);
    
    
    int value = 5;
    cout << "\nDelete by value " << value << ":\n";
    head = delete_by_value(head, value);
    print_linked_list(head);
    
    /* Insertion in LinkedList */
    cout << "\nInsert before head:\n";
    int ele1 = 12;
    head = insert_head(head, ele1);
    print_linked_list(head);

    cout << "\nInsert after tail:\n";
    int ele2 = 98;
    head = insert_tail(head, ele2);
    print_linked_list(head);

    int pos3 = 3;
    int ele3 = 55;
    cout << "\nInsert " << ele3 << " at Position " << pos3 << ":\n";
    head = insert_position(head, ele3, pos3);
    print_linked_list(head);
    
    
    int newEle4 = 54;
    int value4 = 55;
    cout << "\nInsert before the given value: " << value << ":\n";
    head = insert_before_value(head, newEle4, value4);
    print_linked_list(head);
    

    return 0;
}