/**
 * YouTube (Striver's): https://youtu.be/Du881K7Jtk8?si=5AiKjJZZ0bp9vIVU
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * Approach: Variant-2 (Circular Traversal)
 * 1. We'll virtually duplicate the 'arr' in front of original 'arr'.
 * 2. Tarversal index will be from '0' till '2n-1' and we'll use 'i % n' to keep the 
 * traversal within origin arr's limit.
 * 4. Rest of the steps remain same, except when we're modifying the 'nge' array.
 */

vector<int> next_greater_element_variant_2(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i = 2 * n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= arr[i % n]) // remove all smaller elements
            st.pop();
        
        if(i < n) {
            if(!st.empty()) // add 1st greater element
                nge[i] = st.top();
            else
                nge[i] = -1; // if no greater elements in front
        }
        st.push(arr[i % n]);
    }

    return nge;
}


/**
 * Approach: Variant-1
 * 1. Maintain a stack data structure and start parsing the 'arr' from right.
 * 2. While parsing, pop all the stack elements if they're smaller than 'ele'.
 * 3. Assign the 1st larger element as NGE of 'ele'.
 * 4. If there were no elements to be popped in stack, assign -1 as NGE of 'ele'.
 * 5. Push the 'ele' to stack.
 */
vector<int> next_greater_element_variant_1(vector<int> &arr) {
    vector<int> nge(arr.size());
    stack<int> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        
        while(!st.empty() && st.top() <= arr[i]) {
            
            st.pop();
        }
        if(!st.empty())
            nge[i] = st.top();
        else
            nge[i] = -1;
        st.push(arr[i]);
    }

    return nge;
}

int main() {
    vector<int> arr = {4,12,5,3,1,2,5,3,1,2,4,6};
    cout << "Old array:\n";
    for(auto i: arr)
        cout << i << ", ";

    vector<int> result = next_greater_element_variant_1(arr);
    cout << "\nNGE array (Variant-1):\n";
    for(auto i: result)
        cout << i << ", ";

    vector<int> result2 = next_greater_element_variant_2(arr);
    cout << "\nNGE array (Variant-2):\n";
    for(auto i: result2)
        cout << i << ", ";

    return 0;
}