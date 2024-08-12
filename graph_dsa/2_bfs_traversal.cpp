#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

vector<int> traverse_bfs(int n, vector<int> adjL[]) { // Time Complexity: O(N) + O(2E)
    vector<int> visited(n+1, 0);
    visited[1] = 1;

    queue<int> q;
    q.push(1);
    vector<int> ans;

    while(!q.empty()) { // Time Complexity: O(N).
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int i = 0; i < adjL[node].size(); i++) { // Time Complexity of for loop: O(2E) -> degree of graph
            if(visited[adjL[node][i]] != 1) {
                visited[adjL[node][i]] = 1;
                q.push(adjL[node][i]);
            }
        }
    }
    
    return ans;
}

int main() {
    // Adjacency 'Matrix': using 2-D array. Space used: O(N x N)
    int n = 5;
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

    vector<int> ans = traverse_bfs(n, adjList);
    cout << "\nBFS Traversal:\n";
    printAns(ans);
}