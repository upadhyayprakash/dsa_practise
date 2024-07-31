#include <stack>
using namespace std;

stack<int> arr_to_stack(vector<int> &arr) {
    stack<int> st;
    for(auto i: arr) {
        st.push(i);
    }
    return st;
}

void print_stack(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << ", ";
        st.pop();
    }
    cout << endl;
}