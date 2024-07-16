#include <iostream>
#include <vector>
#include <unordered_map>
#include "tree_utility.h"

using namespace std;

/**
 * TODO:
 * 1. Include unmatched keys from 't2'
 * 2. For keys from 't1' with same name (on same level), copy from respective
 * 'key' occurence from 't2'. Eg. 2nd 'A' of 't1' should match with 2nd 'A' from 't2'.
 * 3. If no 2nd occurence present, keep the 't1' node's key as it is.
 */
Node* merge_tree_by_key(Node* t1, Node* t2) {
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

    unordered_map<string, int> mpp1;
    // Recursive calls for matching keys -> modify this with 2-pointer for 1st problem.
    for(int i = 0; i < t1->childNodes.size(); i++) {
        /*
            1. For 't1' nodes, store mapping of 'key' and its occurence. Eg. {A -> 1}
            2. When the same key appears 2nd time, we'll increment its value. Eg. {A -> 2}
            3. We'll use this occurence value to find the nth occurence of same key in 't2'.
            4. If no match found, we'll keep the original node as it is.
            5. If a match is found, we'll merge the 2nd 'A' from both 't1' and 't2'.
        */
       mpp1[t1->childNodes[i]->name] += 1;

       unordered_map<string, int> mpp2;
        for(int j = 0; j < t2->childNodes.size(); j++) {
            mpp2[t2->childNodes[j]->name] += 1;
            if(t1->childNodes[i]->name == t2->childNodes[j]->name && mpp1[t1->childNodes[i]->name] == mpp2[t2->childNodes[j]->name]) {
                t1->childNodes[i] = merge_tree_by_key(t1->childNodes[i], t2->childNodes[j]);
                break;
            }
        }
    }

    // For remaining nodes of 't2'
    unordered_map<string, int> mpp3; // For count of 't2' keys
    for(auto it: t2->childNodes) {
        mpp3[it->name] += 1;
        if(mpp3[it->name] > mpp1[it->name]) {
            t1->childNodes.push_back(it);
        }
    }

    return t1;
}

int main() {
    // 't1' -> global config structure
    Node* t1 = new Node("ROOT-1", "t1");
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
    Node* t2 = new Node("ROOT-2", "t2");
    Node* a2 = new Node("A", "apple");
    a2->childNodes.push_back(new Node("C", "chappal"));
    a2->childNodes.push_back(new Node("Y", "yotta"));
    t2->childNodes.push_back(a2);
    t2->childNodes.push_back(new Node("E", "etta"));
    t2->childNodes.push_back(new Node("B", "banana"));
    t2->childNodes.push_back(new Node("A", "aam"));
    t2->childNodes.push_back(new Node("D", "dollar"));
    t2->childNodes.push_back(new Node("A", "Atta"));

    cout << "\nTree-2:\n";
    render_tree(t2);

    Node* ans = merge_tree_by_key(t1, t2);

    cout << "\nResult Tree:\n";
    render_tree(ans);

    return 0;
}