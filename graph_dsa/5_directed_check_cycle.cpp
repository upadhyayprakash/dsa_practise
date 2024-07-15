#include <iostream>
#include <cstring>
using namespace std;

bool dfsCheckCyclic(int node, vector<int> adjL[], int vis[], int path_vis[]) {
    vis[node] = 1;
    path_vis[node] = 1;

    // traverse adjacent nodes from adjL
    for(auto it: adjL[node]) {
        // when node is not visited
        if(!vis[it]) {
            if(dfsCheckCyclic(it, adjL, vis, path_vis) == true)
                return true;
        } else if(path_vis[it]) { // if node is visited already 
            return true;
        }
    }

    path_vis[node] = 0;
    return false;
}

string is_directed_graph_cyclic_dfs(int V, vector<int> adjL[]) {
    int vis[V];
    int path_vis[V];
    memset(vis, 0, sizeof(vis));
    memset(path_vis, 0, sizeof(path_vis));

    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfsCheckCyclic(i, adjL, vis, path_vis)) return "true";
        }
    }

    return "false";
}

int main() {
    vector<int> adjL[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;
    cout << "Is graph cyclic (DFS)?\n";
    cout << is_directed_graph_cyclic_dfs(V, adjL);
    return 0;
}