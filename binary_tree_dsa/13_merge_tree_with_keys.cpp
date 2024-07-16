#include <iostream>
#include <vector>
#include <unordered_map>
#include "tree_utility.h"

using namespace std;

/**
 * TODO: check for scope of optimisations
 */
Node* merge_tree_by_key(Node* t1, Node* t2) {
    /*
    Approach:
        1. Go through each node 'key' from t1 and find matching node in t2.
        2. Merge the matched node's 'value' if not null (base condition)
        3. If having child nodes, repeat step-1 OR ELSE return
        4. Add the remaining nodes from 't2'
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
    Node* t1 = new Node("env", "base");
    Node* a = new Node("name", "some name");
    a->childNodes.push_back(new Node("metadata", "some metadata"));
    Node* x = new Node("image", "common_payment_app_image");
    x->childNodes.push_back(new Node("registry", "registry.k8s.io"));
    a->childNodes.push_back(x);
    t1->childNodes.push_back(a);
    t1->childNodes.push_back(new Node("port", "0000"));
    t1->childNodes.push_back(new Node("name", "sample_module"));
    t1->childNodes.push_back(new Node("kind", "Pod"));
    t1->childNodes.push_back(new Node("port", "27017"));
    t1->childNodes.push_back(new Node("max_connection", "4"));
    
    cout << "\nTree-1:\n";
    render_tree(t1);
    
    // 't2' -> local config structure
    Node* t2 = new Node("env", "Staging");
    Node* a2 = new Node("name", "payment_app");
    a2->childNodes.push_back(new Node("metadata", "payment-app metadata"));
    a2->childNodes.push_back(new Node("apiVersion", "v1.0"));
    t2->childNodes.push_back(a2);
    t2->childNodes.push_back(new Node("internalEndpoint", "http://internal.ai"));
    t2->childNodes.push_back(new Node("port", "8080"));
    t2->childNodes.push_back(new Node("name", "core_payment_module"));
    t2->childNodes.push_back(new Node("port", "9000"));

    cout << "\nTree-2:\n";
    render_tree(t2);

    Node* ans = merge_tree_by_key(t1, t2);

    cout << "\nResult Tree:\n";
    render_tree(ans);

    return 0;
}