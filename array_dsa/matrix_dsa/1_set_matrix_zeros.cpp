#include <iostream>
using namespace std;

void print_matrix(vector<vector<int>> &matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void set_matrix_zeros(vector<vector<int>> &matrix) {
    int col0 = 1;
    int m = matrix[0].size();
    int n = matrix.size();
    
    // Marks the reference positions. Time Complexity: O(n^2)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if(j != 0) matrix[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    // Update the cells without 1st row and 1st col
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Update the 1st row (except 1st 'cell') --> and then the 1st col (entirely) in next step. No vice-versa
    if(matrix[0][0] == 0)
        for(int j = 0; j < m; j++)
            matrix[0][j] = 0;

    if(col0 == 0)
        for(int i = 0; i < n; i++)
            matrix[i][0] = 0;
}

int main() {
    vector<vector<int>> matrix = {{1,1,1,1}, {1,0,1,1}, {1,1,0,1}, {0,1,1,1}};
    cout << "Original Matrix:\n";
    print_matrix(matrix);

    // set matrix zeros
    set_matrix_zeros(matrix);
    cout << "Updated Matrix:\n";
    print_matrix(matrix);
    return 0;
}