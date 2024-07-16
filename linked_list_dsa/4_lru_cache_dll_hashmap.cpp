#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int key;
        int val;
        Node * next;
        Node * prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
};

class LRUCache {
    public:
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int _capacity) {
        cap = _capacity;
        head -> next = tail;
        tail->prev = head;
    }

    void addNode(Node * newNode) {
        Node * temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
    }

    void deleteNode(Node * delNode) {
        Node * delprev = delNode -> prev;
        Node * delnext = delNode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
        Node * resNode = m[key_];
        int res = resNode -> val;
        m.erase(key_);
        deleteNode(resNode);
        addNode(resNode);
        m[key_] = head -> next;
        return res;
        }

        return -1;
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
        Node * existingNode = m[key_];
        m.erase(key_);
        deleteNode(existingNode);
        }
        if (m.size() == cap) {
        m.erase(tail -> prev -> key);
        deleteNode(tail -> prev);
        }

        addNode(new Node(key_, value));
        m[key_] = head -> next;
    }
};

int main() {
    int capacity = 3;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(1,101);
    cout << "obj->get(1):\n" << obj->get(1) << endl;
    cout << "obj->put(1,101):\n";
    cout << "obj->get(1):\n" << obj->get(1) << endl;
    return 0;
}