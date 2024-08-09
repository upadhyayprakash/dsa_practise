/**
 * Get Kth smallest/largest element in an array.
 */
#include <iostream>
#include <queue>
using namespace std;

int kth_largest_element_brute_force(vector<int> arr, int k) { // TC: O(N * LogN), SC: O(1)
    sort(arr.begin(), arr.end()); // sorted in ascending
    return arr[arr.size() - k]; // for smallest, return arr[k]
}

int kth_largest_element_optimal(vector<int> arr, int k) { // TC: O(N * LogN), SC: O(1)
    priority_queue<int> pqMax; // maxHeap
    for(auto i: arr)
        pqMax.push(i);
    
    // Get the Kth largest element by removing the k-1 elements from maxHeap
    while(k > 1) {
        pqMax.pop();
        k--;
    }
    return pqMax.top();
}

int kth_smallest_element_optimal(vector<int> arr, int k) { // TC: O(N * LogN), SC: O(1)
    priority_queue<int, vector<int>, greater<int>> pqMin; // maxHeap
    for(auto i: arr)
        pqMin.push(i);
    
    // Get the Kth largest element by removing the k-1 elements from maxHeap
    while(k > 1) {
        pqMin.pop();
        k--;
    }
    return pqMin.top();
}

int main() {
    vector<int> arr = {1,2,6,4,5,3};
    int k = 3;
    cout << "kth largest element(brute-force):\n" << kth_largest_element_brute_force(arr, k) << endl;
    cout << "kth largest element(optimal):\n" << kth_largest_element_optimal(arr, k) << endl;
    cout << "kth smallest element(optimal):\n" << kth_smallest_element_optimal(arr, k);
    return 0;
}