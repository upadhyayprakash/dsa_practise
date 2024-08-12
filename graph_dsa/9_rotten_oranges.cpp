/**
 * Find 'minimum' days required to rot all Oranges. If not possible to rot all, return -1.
 * YouTube(Striver's): https://www.youtube.com/watch?v=yf3oUhkvqA0
 * Pattern: matrix, bfs
 */

#include <iostream>
#include <queue>
using namespace std;

/**
 * Approach:
 * 0. Input matrix 'grid' and its cells can contain either 0, 1 or 2.
 *      0 -> No Orange, 1 -> Fresh orange, 2 -> Rotten orange
 * 1. Use BFS with queue to travese level-wise. Store (row, col, time), where 'time' is
 * 2. the time it took to reach this orange. Initially put all the rotten oranges ('2') into queues.
 * 3. 'visited' -> Initialize a visited matrix with '0' and mark all 'visited' nodes as '2' when traversing.
 * 4. At the end, compare original 'grid' matrix with rotten 'result' matrix and return 
 */
int days_for_rotten_orange(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int visited[m][n];

    queue<pair<pair<int, int>, int>> q; // Stores <<row, col>, time>, where time is the unit time it took to reach this orange.
    
    // Step-1: Fill the Visited matrix and Queue with rotten oranges.
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            } else { // not a rotten orange, 
                visited[i][j] = 0; // otherwise, garbage value is stored
            }
        }
    }

    // print initial matrix
    cout << "Original Matrix:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    // print initial visited matrix
    cout << "\nVisited Matrix:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }

    // neighbour index (top, right, bottom, left)
    int rowIdx[] = {-1, 0, 1, 0};
    int colIdx[] = {0, 1, 0, -1};
    int timeCount = 0;

    // Step-2: BFS to update 'reachable' neighbouring oranges.
    while(!q.empty()) {
        // remove top node and fill visited and result matrix
        pair<pair<int, int>, int> cell = q.front();
        int row = cell.first.first;
        int col = cell.first.second;
        int time = cell.second;
        timeCount = max(timeCount, time);
        q.pop();

        // check 'eligible' neighbouring cells for fresh oranges
        for(int i = 0; i < 4; i++) {
            int cellRow = row + rowIdx[i];
            int cellCol = col + colIdx[i];

            if(cellRow >= 0 && cellRow < m && cellCol >= 0 && cellCol < n
                && visited[cellRow][cellCol] != 2 && grid[cellRow][cellCol] == 1) {
                    q.push({{cellRow, cellCol}, time + 1});
                    visited[cellRow][cellCol] = 2;
                }
        }
    }

    // Step-3: Check if all oranges are rotten or else return -1
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1 && visited[i][j] != 2)
                return -1;
        }
    }

    return timeCount;
}

int main() {
    vector<vector<int>> matrix = {{2,1,1}, {1,1,0},{0,1,1}};
    int count = days_for_rotten_orange(matrix);
    cout << "\nDays for Rotten oranges:\n" << count;
    return 0;
}