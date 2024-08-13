/**
 * Topological Sorting order for the given DAG (Directed Acyclic Graph)
 * YouTube(Striver's): https://www.youtube.com/watch?v=5lZ0iJMrUMk
 * Pattern: graph, dag, dfs
 */

#include <iostream>
#include <stack>
using namespace std;

void dfs(int node, vector<int> adjList[], vector<int> &visited, stack<int> &st) {
    visited[node] = 1;
    
    for(auto it: adjList[node]) {
        if(!visited[it])
            dfs(it, adjList, visited, st);
    }
    st.push(node);
}

/**
 * Approach:
 * 1. We'll perform DFS with a visited array.
 * 2. We'll also maintain a 'stack' for storing the independent nodes
 */
void print_topological_sorted_order(vector<int> adjList[], int V) { // TC: O(V + E), SC: O(2N)
    vector<int> visited(V, 0);
    stack<int> st;
    for(int i = 0; i < V; i++) {
        if(!visited[i])
            dfs(i, adjList, visited, st);
    }

    while(!st.empty()) {
        int ele = st.top();
        st.pop();
        cout << ele << " ";
    }
}

int main() {
    //V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
    print_topological_sorted_order(adj, V);
    return 0;
}