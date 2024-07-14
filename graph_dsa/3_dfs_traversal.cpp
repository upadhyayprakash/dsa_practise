#include <iostream>
#include <vector>

using namespace std;

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

void traverse_dfs(int node, vector<int> adjL[], vector<int> &visited, vector<int> &ans) { // Time Complexity: O(N) + O(2E)
    visited[node] = 1;
    ans.push_back(node);
    
    for(auto i: adjL[node]) {
        if(!visited[i])
            traverse_dfs(i, adjL, visited, ans);
    }
}

int main() {
    // Adjacency 'Matrix': using 2-D array. Space used: O(N x N)
    int n = 5;
    int m = 6;
    vector<pair<int, int>> edges = {
        {1, 3},
        {2, 4},
        {1, 4},
        {5, 4},
        {3, 5},
        {5, 1}
    };
    vector<int> adjList[6];
    
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // comment this line for 'directed' graph
    }

    // Print the Adjacency List
    cout << "\nAdjacency List:\n";
    for(int i = 0; i <= n; i++) {
        cout << i << " -> ";
        for(int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << ", ";
        }
        cout << endl;
    }

    vector<int> visited(n+1, 0);
    vector<int> ans;
    traverse_dfs(1, adjList, visited, ans);
    cout << "\nDFS Traversal:\n";
    printAns(ans);
}