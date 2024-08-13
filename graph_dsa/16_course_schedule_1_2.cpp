/**
 * For given pair of tasks, return order of tasks as array of nodes. If not possible, return empty array.
 * YouTube(Striver's): https://www.youtube.com/watch?v=WAOfKpxYHR8
 * Pattern: graph, dag, topological sort
 */

/**
 * Task-1: Check if cycle exists
 * Task-2: Return order of Tasks, if no Cycle
 */

#include <iostream>
#include <queue>
using namespace std;

vector<int> find_topological_order(int V, int m, vector<vector<int>> adjPair) {
    // step-0: create adjacency list
    vector<int> adjList[V];
    for(auto it: adjPair) {
        adjList[it[1]].push_back(it[0]);
    }

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

    vector<int> topoResult;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topoResult.push_back(node);
        for(auto i: adjList[node]) {
            indegree[i]--; // reduce the indegree (or dependency) by 1
            if(indegree[i] == 0) // if node has no indegree (or dependency)
                q.push(i);
        }
    }
    if(topoResult.size() == V) return topoResult;
    else return {};
}

int main() {
    int N = 4;
	int M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);
    vector<int> result = find_topological_order(N, M, prerequisites);
    for(auto it: result)
        cout << it << " ";
    return 0;
}