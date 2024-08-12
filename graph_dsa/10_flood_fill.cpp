/**
 * Flood fill a 2D matrix.
 * YouTube(Striver's): https://www.youtube.com/watch?v=C-2_uSRli8o
 */

#include <iostream>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &result, vector<vector<int>> &image, int targetColor, int rowIdx[], int colIdx[], int initialColor) {
    // process node and mark visited(i.e. mark with new color)
    result[row][col] = targetColor;

    // traverse nodes that's not colored and eligible for coloring
    int m = image.size();
    int n = image[0].size();

    for(int i = 0; i < 4; i++) {
        int cellRow = row + rowIdx[i];
        int cellCol = col + colIdx[i];

        if(cellRow >= 0 && cellRow < m && cellCol >= 0 && cellCol < n
            && image[cellRow][cellCol] == initialColor && result[cellRow][cellCol] != targetColor) {
                dfs(cellRow, cellCol, result, image, targetColor, rowIdx, colIdx, initialColor);
            }
    }
}

vector<vector<int>> flood_fill(vector<vector<int>> image, int row, int col, int targetColor) { // TC: O(m x n), SC: O(m x n)
    int initialColor = image[row][col];

    // create copy of image (don't modify original image)
    vector<vector<int>> result = image;

    // neighbour index (top, right, bottom, left)
    int rowIdx[] = {-1, 0, 1, 0};
    int colIdx[] = {0, 1, 0, -1};

    dfs(row, col, result, image, targetColor, rowIdx, colIdx, initialColor);
    return result;
}

int main() {
    vector<vector<int>> image = {
        {1,1,1},
	    {1,1,0},
	    {1,0,1}
    };
    int m = image.size();
    int n = image[0].size();
    cout << "Original Image:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << image[i][j] << " ";
        cout << endl;
    }

    vector<vector<int>> result = flood_fill(image, 1, 1, 2);
    cout << "Flood filled image:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}