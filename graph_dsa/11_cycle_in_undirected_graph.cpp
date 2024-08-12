/**
 * Detect cycle in Undirected Graph
 * YouTube(Striver's): https://www.youtube.com/watch?v=BPlrALf1LDU
 * Pattern: graph, bfs/dfs
 */

#include <iostream>
#include <queue>
using namespace std;

bool bfs_detect(int node, vector<int> adj[], vector<int> &visited) {
    visited[node] = 1;
    
    queue<pair<int, int>> q;
    q.push({node, -1}); // no parent for start node
    
    while(!q.empty()) {
        pair<int, int> frontPair = q.front();
        int n = frontPair.first;
        int parent = frontPair.second;
        q.pop();

        for(auto i: adj[n]) {
            if(visited[i] != 1) {
                visited[i] = 1;
                q.push({i, n});
            } else if(parent != i)
                    return true;
        }
    }
    return false;
}

bool detect_cycle(vector<int> adj[], int V) {
    vector<int> vis(V, 0);
    for(int i = 0;i<V;i++) {
        if(!vis[i]) {
            if(bfs_detect(i, adj, vis)) return true; 
        }
    }
    return false; 
}

int main() {
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2,3}, {1, 3}, {2,3}}; // Cycle Present

    cout << "Adjacency List:\n";
    for(int i = 0; i < 4; i++) {
        cout << i << " -> ";
        for(auto j: adj[i])
            cout << j << ", ";
        cout << endl;
    }

    cout << "\nCycle Present?\n" << (detect_cycle(adj, 4) ? "YES" : "NO");
    return 0;
}