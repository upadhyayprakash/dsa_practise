/**
 * Kahn's Algorithm for Topological Sorting in DAG (Directed Acyclic Graph)
 * YouTube(Striver's): https://www.youtube.com/watch?v=73sneFXuTEg
 * Pattern: graph, dag, bfs
 */

#include <iostream>
#include <queue>
using namespace std;

/**
 * Approach:
 * 1. Maintain an 'indegree' array for count of indegree for each graph node.
 * 2. Take nodes with '0' indegree and push to 'queue' and print its value as output.
 * 3. Process each queue node for its neighbour and reduce neighbour's indegree by 1.
 * 4. If the neighbour's indegree becomes '0', push that also to queue.
 * 5. Keep doing until the queue is empty.
 */
void print_topological_sorted_order_bfs_kahn(vector<int> adjList[], int V) { // TC: O(V + E) for directed graph, SC: O(V), for 'queue' and 'indegree'
    // step-1: calculate indegree of each node
    vector<int> indegree(V,0);
    for(int i = 0; i < V; i++) {
        for(auto it: adjList[i]) {
            indegree[it]++;
        }
    }

    // Eg. indegree: [2, 2, 1, 1, 0, 0]

    // step-2: push initial set of '0' indegree nodes to queue
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto i: adjList[node]) {
            indegree[i]--; // reduce the indegree (or dependency) by 1
            if(indegree[i] == 0) // if node has no indegree (or dependency)
                q.push(i);
        }
    }
}

int main() {
    //V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
    print_topological_sorted_order_bfs_kahn(adj, V);
    return 0;
}