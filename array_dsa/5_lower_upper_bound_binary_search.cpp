#include <iostream>

using namespace std;

/**
 * Given a sorted array, find the 'floor' value for the given 'target'
 * Approach:
 * - floor is a value either equal or just smaller than 'target'
 * - If no such value possible, return -1
 */
int get_floor(vector<int> arr, int n, int target) {
    int ans = -1;
    int low = 0;
    int  high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;
        } else
            high = mid - 1;
    }

    return ans;
}


/**
 * Given a sorted array, find the 'ceil' value for the given 'target'
 * Approach:
 * - Ceil is same as lower-bound
 * - Use same algo but return the 'value' of lower-bound instead of its 'index'.
 * - If no such value possible, return -1
 */
int get_ceil(vector<int> arr, int n, int target) {
    int ans = -1;
    int low = 0;
    int  high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= target) {
            ans = arr[mid];
            high = mid - 1;
        } else
            low = mid + 1;
    }

    return ans;
}

/**
 * Search Insert Position:
 * - It's similar to finding 'lower-bound' for a 'target' ele in sorted array.
 * - Same algo as lower-bound
 */
int find_insert_position(vector<int> &arr, int n, int target) { // Time Complexity: O(log2N)
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


/**
 * A upper bound means an element that's > target. We'll return the index of that 'ele'
 * or a pseudo index 'n' if no such lower bound is possible.
 */
int get_upper_bound_index(vector<int> &arr, int n, int target) { // Time Complexity: O(log2N)
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
int get_lower_bound_index(vector<int> &arr, int n, int target) { // Time Complexity: O(log2N)
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

/**
 * Find 'first' and 'last' occurence of the given number in an array.
 */
pair<int, int> get_first_last_occurence(vector<int> &arr, int n, int target) { // Time Complexity: O(logN)
    int lb = get_lower_bound_index(arr, n, target);
    if(lb == n || arr[lb] != target)
        return {-1, -1};
    
    int ub = get_upper_bound_index(arr, n, target);
    return {lb, ub - 1};
}

int main() {
    vector<int> arr = {1,2,3,4,5,7,7,8,9,10};
    int n = arr.size();
    int target = 7;
    cout << "Lower Bound of " << target << ":\n";
    cout << get_lower_bound_index(arr, n, target);

    cout << "\n\nUpper Bound of " << target << ":\n";
    cout << get_upper_bound_index(arr, n, target);

    cout << "\n\nInsert Position of " << target << ":\n";
    cout << find_insert_position(arr, n, target);

    cout << "\n\nCeil of " << target << ": \n";
    cout << get_ceil(arr, n, target);

    cout << "\n\nFloor of " << target << ": \n";
    cout << get_floor(arr, n, target);

    cout << "\n\n1st and last index of " << target << ":\n";
    pair<int, int> result = get_first_last_occurence(arr, n, target);
    cout << "{" << result.first << ", " << result.second << "}";

    return 0;
}