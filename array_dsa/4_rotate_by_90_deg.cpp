#include <iostream>
#include <iomanip>
#include <vector>
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


/**
 * Brute-force approach to rotate a matrix.
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2) <-- This is bad
 */
vector<vector<int>> rotate_by_90_brute_force(vector<vector<int>> matrix) {
    /*
    Formula for Right Rotate: m'[j][n-1-i] = m[i][j]
    */
   vector<vector<int>> ans(matrix.size(), vector<int>(matrix.size(),0));
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size(); j++) {
            ans[j][matrix.size()-1-i] = matrix[i][j];
        }
    }

    return ans;
}

/**
 * Optimal Approach: It uses 'Transpose' of matrix along with 'Mirror' (relfection)
 */

void rotate_by_90_optimal(vector<vector<int>> &matrix) {
    // Transpose: Swap along the diagonal axes
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]); // --> note the formula
        }
    }

    // Reflection: Swap along vertical center axis
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size()/2; j++) {
            swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]); // --> note the formula
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    cout << "Original Matrix:\n";
    print_matrix(matrix);

    // rotate by 90deg: Brute-force
    cout << "\nRotated Matrix (brute-force):\n";
    vector<vector<int>> ans = rotate_by_90_brute_force(matrix);
    print_matrix(ans);

    // rotate by 90deg: Optimal
    cout << "\nRotated Matrix (optimal):\n";
    rotate_by_90_optimal(matrix);
    print_matrix(matrix);

    return 0;
}