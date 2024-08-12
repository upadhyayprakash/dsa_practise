/**
 * Count number of provinces in a given graph. A graph can have multiple components.
 * YouTube(Striver's): https://www.youtube.com/watch?v=ACzkVtewUYA
 * Pattern: graph, dfs, bfs
 */

#include <iostream>
using namespace std;

void dfs(int node, vector<int> adjList[], vector<int> &visited) {
    visited[node] = 1;
    for(auto it: adjList[node])
        if(visited[it] != 1)
            dfs(it, adjList, visited);
}

int count_province(vector<vector<int>> adjMatrix, int V) {
    // step-1: Convert adjMatrix to adjList
    vector<int> adjList[V];
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i != j && adjMatrix[i][j] == 1)
                adjList[i].push_back(j);
        }
    }

    // Print Adjacency List
    cout << "Adjancency List:\n";
    for(int i = 0; i < V; i++) {
        cout << i << " -> ";
        for(auto it: adjList[i])
            cout << it << ", ";
        cout << endl;
    }
    
    // step-2: Traverse each node in 'adjList' and use 'dfs' to mark conected nodes as 'visited'
    int count = 0;
    vector<int> visited(V, 0);
    for(int i = 0; i < V; i++) {
        if(visited[i] != 1) {
            count++;
            dfs(i, adjList, visited);
        }
    }
    return count;
}

int main() {
    int V = 8;
    vector<vector<int>> adjMatrix {
        {1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1},
    };

    int result = count_province(adjMatrix, V);
    cout << "Province Count:\n" << result;
    
    return 0;
}