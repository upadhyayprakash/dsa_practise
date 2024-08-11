/**
 * YouTube(Striver's): https://www.youtube.com/watch?v=bR7mQgwQ_o8
 */

#include <iostream>
using namespace std;

/**
 * To get nth row's 'c' column value of Pascal's Triangle, use formula,
 * (n-1)C(r-1), Hence, 5C3 becomes 4C2
 */
int get_nCr(int n, int r) {
    long long res = 1;
    for(int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

/**
 * Approach: Using nCr optimised logic
 * 1. We'll use previous answer in next step as it's a series.
 * 2. Formula: prev_ans * (n - i) / i
 * 3. To start, 1st prev_ans = 1. Hence,
 *  a. for 5C3, 1 * (5-1) / 1 --> 1 * 4 / 1 --> 4
 *  b. for 5C4, 4 * (5-2) / 2 --> 4 * 3 / 2 --> 6 and so on.
 */
vector<int> get_nth_pascal_row(int n) { // TC: O(N), SC: O(1)
    vector<int> result = {1}; // add first value of the row as '1'
    long long ans = 1;
    for(int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        result.push_back(ans);
    }
    return result;
}

vector<vector<int>> get_pascals_triangle_till_n_rows_brute(int n) { // TC: O(N * N * r)
    vector<vector<int>> result;
    for(int i = 1; i < n; i++) {
        vector<int> rowResult;
        for(int j = 1; j <= i; j++) {
            rowResult.push_back(get_nCr(i-1,j-1));
        }
        result.push_back(rowResult);
    }
    return result;
}

vector<vector<int>> get_pascals_triangle_till_n_rows_optimal(int n) { // TC: O(N * N * r)
    vector<vector<int>> result;
    for(int i = 1; i < n; i++) {
        result.push_back(get_nth_pascal_row(i));
    }
    return result;
}

int main() {
    int r = 5;
    int c = 3;
    cout << "nCr element:\n" << get_nCr(r-1, c-1);
    
    vector<int> pascalRow = get_nth_pascal_row(r);
    cout << "\nnth Pascal row:\n";
    for(auto i: pascalRow)
        cout << i << " ";

    cout << "\nPascal's Triangle for row (brute): " << r << endl;
    vector<vector<int>> result = get_pascals_triangle_till_n_rows_brute(r+1);
    for(auto i: result) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "\nPascal's Triangle for row (optimal): " << r << endl;
    vector<vector<int>> result2 = get_pascals_triangle_till_n_rows_optimal(r+1);
    for(auto i: result2) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}