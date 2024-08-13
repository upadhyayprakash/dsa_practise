/**
 * Count Distinct Islands or Connected Components in a matrix
 * YouTube(Striver's): https://www.youtube.com/watch?v=muncqlKJrH0
 * Pattern: graph, bfs/dfs, matrix/2D-Array
 */

#include <iostream>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited) {
    visited[i][j] = 1;
    
    int n = grid.size();
    int m = grid[0].size();

    // mark all its neighbours '1' recursively
    for(int row = -1; row <= 1; row++) {
        for(int col = -1; col <= 1; col++) {
            int rowIdx = i + row;
            int colIdx = j + col;
            if(rowIdx >= 0 && rowIdx < n && colIdx >= 0 && colIdx < m
                && !visited[rowIdx][colIdx] && grid[rowIdx][colIdx] != 0)
                dfs(rowIdx, colIdx, grid, visited);
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
    int count = 0;

    
    // Perform DFS and count starting node and return as answer
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && visited[i][j] != 1) { // first valid node
                dfs(i, j, grid, visited);
                count++;
            }
        }
    }


    return count;
}

int main() {
    // n: row, m: column
    vector<vector<int>> grid
    {
        {0,1,1,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,0},
        {1,1,0,1},
    };

    int islandCount = count_islands(grid);
    cout << "Distinct Islands:\n" << islandCount;
    return 0;
}