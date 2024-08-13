/**
 * Detect a Cycle in Directed graph.
 * YouTube(Striver's): https://www.youtube.com/watch?v=9twcmtQj4DU
 * Pattern: graph, dfs
 */

#include <iostream>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited) {
    visited[node] = 1;
    pathVisited[node] = 1;

    // call 'dfs' for neighbours
    for(auto it: adj[node]) {
        if(!visited[it]) { // node not visited
            if(dfs(it, adj, visited, pathVisited)) {
                return true;
            }
        }
        else if(pathVisited[it]) // if visited and pathVisited, then a 'cycle' is present
                return true;
    }
    pathVisited[node] = 0;
    return false;
}

/** 
 * Approach: If a node is 'visited' and 'pathVisited' then there's a cycle.
 * 1. We maintain two arrays, 'visited' and 'pathVisited' to indicate the node is on same active path.
 * 2. 'pathVisited' helps know if the past node was on the same path, hence a cycle.
 * 3. We'll remove 'pathVisited' entry (mark as '0') whenever returning with 'false' form
 * a node. As the node is not on cyclic path from that traverse. But the same 'node' may be part of another cycle.
 * 
 */
bool detect_cycle(int V, vector<int> adjList[]) { // TC: O(V + E)
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(i, adjList, visited, pathVisited)) return true;
        }
    }
    return false;

}

int main() {
    // V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
    cout << "Is cycle present?\n" << (detect_cycle(V, adj) ? "YES" : "NO");
    return 0;
}