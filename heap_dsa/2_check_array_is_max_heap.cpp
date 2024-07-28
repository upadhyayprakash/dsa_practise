#include <iostream>
#include <queue>
using namespace std;

bool check_arr_is_max_heap(vector<int> &arr, int i = 0) {
    // Base Condition: last internal node (non-leaf node)
    if(i >= (arr.size() - 1)/2)
        return true; // return true if leaf node

    int leftChild = arr[2*i + 1];
    int rightChild = arr[2*i + 2];
    
    if(arr[i] >= leftChild
        && arr[i] >= rightChild
        && check_arr_is_max_heap(arr, 2*i + 1)
        && check_arr_is_max_heap(arr, 2*i + 1)) {
        
        return true;
    }
    
    return false;
}

bool check_arr_is_min_heap(vector<int> &arr, int i = 0) {
    // Base Condition: last internal node (non-leaf node)
    if(i > (arr.size() - 1)/2)
        return true; // return true if leaf node

    bool left = arr[i] <= arr[2*i + 1] && check_arr_is_min_heap(arr, 2*i + 1);

    // check if right child exists
    bool right = 2*i + 2 == arr.size() || arr[i] <= arr[2*i + 2] && check_arr_is_min_heap(arr, 2*i + 2);
    
    return left && right;
}

int main() {
    vector<int> arr = {90,15,10,7,12,2};
    cout << "Is array a maxHeap?\n";
    cout << (check_arr_is_max_heap(arr) ? "YES" : "NO");

    vector<int> arr2 = {2,10,7,12,15,4};
    cout << "\nIs array a minHeap?\n";
    cout << (check_arr_is_min_heap(arr2) ? "YES" : "NO") << endl;

    return 0;
}