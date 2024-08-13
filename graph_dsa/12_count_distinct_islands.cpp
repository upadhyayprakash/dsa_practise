/**
 * Count Distinct Islands or Connected Components in a matrix
 * YouTube(Striver's): https://www.youtube.com/watch?v=muncqlKJrH0
 * Pattern: graph, bfs/dfs, matrix/2D-Array
 */

#include <iostream>
#include <set>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, 
        vector<pair<int, int>> &path, int &baseRow, int &baseCol) {
    visited[i][j] = 1;
    
    int n = grid.size();
    int m = grid[0].size();

    path.push_back({i - baseRow, j - baseCol});

    // mark all its neighbours '1' recursively
    for(int row = -1; row <= 1; row++) {
        for(int col = -1; col <= 1; col++) {
            int rowIdx = i + row;
            int colIdx = j + col;
            if(rowIdx >= 0 && rowIdx < n && colIdx >= 0 && colIdx < m
                && !visited[rowIdx][colIdx] && grid[rowIdx][colIdx] != 0)
                dfs(rowIdx, colIdx, grid, visited, path, baseRow, baseCol);
        }
    }
}

int count_islands(vector<vector<int>> grid) { // TC: O(m x n), SC: O(m x n), for visited matrix.
    int n = grid.size();
    int m = grid[0].size();
    
    cout << "Original Grid:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    //Create a visited array of same size as grid
    vector<vector<int>> visited(n, vector<int>(m,0));
    
    // Use set to store unique island node coordinates
    set <vector <pair <int, int>>> st;

    
    // Perform DFS and count starting node and return as answer
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && visited[i][j] != 1) { // first valid node
                // To store the path of cells
                vector<pair<int,int>> path;

                dfs(i, j, grid, visited, path, i, j);
                st.insert(path);
            }
        }
    }

    // Set Contents
    cout << "\nSet Contents:\n";
    for(auto it: st) {
        for(auto it1: it) {
            cout << it1.first << ":" << it1.second << " ";
        }
        cout << endl;
    }
    
    return st.size();
}

int main() {
    // n: row, m: column
    vector<vector<int>> grid
    {
        // {0,1,1,0}, {0,1,1,0}, {0,0,1,0}, {0,0,0,0}, {1,1,0,1}, // Test Case-1
        
        // {1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1},{1, 1, 0, 1, 1} // Test Case-2

        {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 0, 0},{0, 0, 0, 1, 1}} // Test Case-3
    };

    int islandCount = count_islands(grid);
    cout << "\nDistinct Islands:\n" << islandCount;
    return 0;
}