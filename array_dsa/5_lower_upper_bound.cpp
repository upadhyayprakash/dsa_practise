#include <iostream>

using namespace std;

/**
 * A upper bound means an element that's > target. We'll return the index of that 'ele'
 * or a pseudo index 'n' if no such lower bound is possible.
 */
int get_upper_bound_index(vector<int> arr, int n, int target) { // Time Complexity: O(log2N)
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > target) {
            ans = mid;
            high = mid - 1; // search left space
        } else {
            low = mid + 1; // search right space
        }
    }

    return ans;
}

/**
 * A lower bound means an element that's >= target. We'll return the index of that 'ele'
 * or a pseudo index 'n' if no such lower bound is possible.
 */
int get_lower_bound_index(vector<int> arr, int n, int target) { // Time Complexity: O(log2N)
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= target) {
            ans = mid;
            high = mid - 1; // search left space
        } else {
            low = mid + 1; // search right space
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5,7,7,8,9,10};
    int n = arr.size();
    int target = 7;
    cout << "Lower Bound of " << target << ":\n";
    cout << get_lower_bound_index(arr, n, target);

    cout << "\n\nUpper Bound of " << target << ":\n";
    cout << get_upper_bound_index(arr, n, target);

    return 0;
}