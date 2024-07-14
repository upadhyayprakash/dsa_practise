#include <iostream>
using namespace std;

int main() {
    // Adjacency 'Matrix': using 2-D array. Space used: O(N x N)
    int n, m;
    cin >> n >> m;
    cout << "Adjacency Matrix (undirected):\n";
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Print the Adjacency Matrix
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // Adjacency List: using 'array' of 'list (vector)'.  Space used: O(2 x E)
    cout << "\nAdjacency List (undirected):\n";
    cin >> n >> m;
    vector<int> adjL[n+1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u); // comment this line for 'directed' graph
    }

    // Print the Adjacency List
    for(int i = 0; i <= n; i++) {
        cout << i << " -> ";
        for(int j = 0; j < adjL[i].size(); j++) {
            cout << adjL[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}