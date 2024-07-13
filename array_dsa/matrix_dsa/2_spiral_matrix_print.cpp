#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void print_matrix(vector<vector<int>> &matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << setw(3);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void print_spiral(vector<vector<int>> &matrix) { // Time Complexity: O(mxn)
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    int left = 0;

    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }

        top++;

        for(int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }

        right--;
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    cout << "Original Matrix:\n";
    print_matrix(matrix);

    // Print matrix in spiral.
    cout << "\nSpiral Output:\n";
    print_spiral(matrix);
    return 0;
}