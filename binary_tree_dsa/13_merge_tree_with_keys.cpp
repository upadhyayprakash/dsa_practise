#include <iostream>
#include <vector>
#include "tree_utility.h"

using namespace std;

Node* merge(Node* t1, Node* t2) {
    /*
    Approach:
        1. Go through each node 'key' from t1 and find matching node in t2.
        2. Merge the matched node's 'value' if not null (base condition)
        3. If having child nodes, repeat step-1 OR ELSE return
    */
    // Base Condition
    if(t1 == nullptr)
        return t2;
    if(t2 == nullptr)
        return t1;
    
    // Process: merge content of nodes
    t1->value = t2->value;

    // Recursive calls
    for(int i = 0; i < t1->childNodes.size(); i++) {
        for(int j = 0; j < t2->childNodes.size(); j++) {
            if(t1->childNodes[i]->name == t2->childNodes[i]->name) {
                t1->childNodes[i] = merge(t1->childNodes[i], t2->childNodes[j]);
                break;
            }
        }
    }

    return t1;
}

int main() {
    // 't1' -> global config structure
    Node* t1 = new Node("ROOT", "t1");
    Node* a = new Node("A", "alpha");
    a->childNodes.push_back(new Node("C", "beta"));
    Node* x = new Node("X", "phi");
    x->childNodes.push_back(new Node("Z", "mu"));
    a->childNodes.push_back(x);
    t1->childNodes.push_back(a);
    t1->childNodes.push_back(new Node("B", "gamma"));
    t1->childNodes.push_back(new Node("A", "delta"));
    t1->childNodes.push_back(new Node("C", "epsilon"));
    t1->childNodes.push_back(new Node("B", "theta"));
    t1->childNodes.push_back(new Node("D", "delta"));
    
    cout << "\nTree-1:\n";
    render_tree(t1);
    
    // 't2' -> local config structure
    Node* t2 = new Node("ROOT", "t2");
    Node* a2 = new Node("A", "apple");
    a2->childNodes.push_back(new Node("C", "chappal"));
    a2->childNodes.push_back(new Node("Y", "yotta"));
    t2->childNodes.push_back(a2);
    t2->childNodes.push_back(new Node("E", "etta"));
    t2->childNodes.push_back(new Node("B", "banana"));
    t2->childNodes.push_back(new Node("A", "aam"));
    t2->childNodes.push_back(new Node("D", "dollar"));

    cout << "\nTree-2:\n";
    render_tree(t2);

    // Node* ans = merge(t1, t2);

    // print_pre_order(ans, 1);

    return 0;
}