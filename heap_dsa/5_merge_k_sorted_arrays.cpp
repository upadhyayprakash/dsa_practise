/**
 * Merge 'k' sorted arrays
 */

#include <iostream>
#include <queue>
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

class CompareClass {
    public:
    bool operator() (Node* &node1, Node* &node2) { // operator overloading
        return node1->data > node2->data;
    }
};

Node* merge_k_sorted_lists_better(vector<Node*> &lists) { // TC: O(NLogK), SC: O(N)
    priority_queue<Node*, vector<Node*>, CompareClass> pqMin;
    // Step-1: Push head node of each list
    for(auto l: lists) // TC: O(LogK)
        pqMin.push(l);
    
    // Step-2: 
    Node* dummyHead = new Node(0);
    Node* mover = dummyHead;
    while(!pqMin.empty()) { // O(N): Runs till all N nodes are iterated
        Node* node = pqMin.top();
        pqMin.pop(); // O(1)
        mover->next = node;
        mover = mover->next;
        if(mover->next)
            pqMin.push(mover->next); // O(LogK)
    }
    return dummyHead->next;
}

Node* merge2Lists(Node* list1, Node* list2) {
    Node* head = new Node(0);
    Node* mover = head;
    while(list1 && list2) {
        if(list1->data <= list2->data) {
            mover->next = list1;
            list1 = list1->next;
        } else {
            mover->next = list2;
            list2 = list1;
            list1 = mover->next->next;
        }
        mover = mover->next;
    }
    if(list1)
        mover->next = list1;
    else
        mover->next = list2;
    
    return head->next;
}

/**
 * Approach: LinkedList Divide-and-Conquer (k = number of lists)
 * 1. We'll merge 2 lists (1st and 2nd list) at a time (interval = 1) and store result in 1st list (in-place).
 * 2. Then, we'll double the interval and merge 1st and 3rd list. Likewise, we'll keep increasing the interval.
 * 3. Finally, when interval > k, where 'k' is number of lists.
 * TC: O(NLogK), where 'N' is the time taken to merge 2 sorted lists, and LogK is number of such merges as we'e diving the range by 2.
 * SC: O(1), no extra space as merge is in-place.
 */
Node* merge_k_sorted_lists_optimal(vector<Node*> &lists) { // Divide and Conquer
    int size = lists.size();
    int interval = 1;
    while(interval < size) {
        for(int i = 0; i < size - interval; i += 2 * interval) {
            lists[i] = merge2Lists(lists[i], lists[i+interval]);
        }
        interval *= 2;
    }
    return lists[0];
}

int main() {
    Node* head1 = new Node(1, new Node(2, new Node(3)));
    Node* head2 = new Node(4, new Node(5, new Node(6)));
    Node* head3 = new Node(7, new Node(8, new Node(9)));
    
    vector<Node*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    Node* mergeList = merge_k_sorted_lists_better(lists);

    // print result
    cout << "Merged k Sorted arrays:(brute):\n";
    Node* temp = mergeList;
    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }


    // 
    head1 = new Node(1, new Node(2, new Node(3)));
    head2 = new Node(4, new Node(5, new Node(6)));
    head3 = new Node(7, new Node(8, new Node(9)));
    
    vector<Node*> lists2;
    lists2.push_back(head1);
    lists2.push_back(head2);
    lists2.push_back(head3);

    Node* mergeList2 = merge_k_sorted_lists_optimal(lists2);

    // print result
    cout << "\nMerged k Sorted arrays:(optimal):\n";
    Node* temp2 = mergeList2;
    while(temp2) {
        cout << temp2->data << " -> ";
        temp2 = temp2->next;
    }
    return 0;
}