/**
 * Search element in sorted array
 * Pattern: Binary search in 1D array
 */
#include <iostream>
using namespace std;

int binary_search(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {3,4,6,7,9,12,16,17};
    int target = 7;
    cout << "target index:\n" << binary_search(arr, target);
    return 0;
}