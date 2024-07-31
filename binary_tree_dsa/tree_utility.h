#include <iostream>
using namespace std;

class Node {
    public:
        string name;
        string value;
        vector<Node*> childNodes;

        Node(string _name, string _value) {
            name = _name;
            value = _value;
            childNodes = {};
        }
};


void render_tree(Node* node, string prefix = "", bool isLast = true)
{
    if( node != nullptr )
    {
        cout << prefix;

        cout << (!isLast ? "├──" : "└──" );

        // print the value of the node
        cout << node->name << " (" << node->value << ")" << endl;

        for(int i = 0; i < node->childNodes.size(); i++) {
            render_tree(node->childNodes[i], prefix + (!isLast ? "│   " : "    "), (i == (node->childNodes.size() - 1)));
        }
    }
}
