#include <iostream>
using namespace std;

/**
 * In a array of 1s and 0s, print length of longest consecutive ONEs sub-array, given
 * that you can at max flip 'k' 0s to 1.
 * 
 * Approach: We can translate the Qs into "Find longest sub-array with at most 'k' zeroes."
 */
int max_consecutive_ones(vector<int> &arr, int n, int k) {
    // ToDo: https://youtu.be/3E4JBHSLpYk?si=RIwBXvZ5TB4wwviq
    return 0;
}

int main() {
    vector<int> arr = {};
    int k = 2;
    cout << "Max Consecutive Ones length:\n" << max_consecutive_ones(arr, arr.size(), k) << endl;
    return 0;
}