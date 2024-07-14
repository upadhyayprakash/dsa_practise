// YouTube: https://youtu.be/tp8JIuCXBaU?si=oP2qVAFfocfakd4Z
#include <iostream>
#include <vector>
using namespace std;

// Approach: We'll use 3-pointer technique to solve this. DNF Flag.
void sort_0s_1s_2s_optimal(vector<int> &arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while(mid <= high) {
        if(arr[mid] == 0) { // if 'ele' is 0
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) { // if 'ele' is 1
            mid++;
        }
        else if(arr[mid] == 2) { // if 'ele' is 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {0,1,1,0,1,2,1,2,0,0,0};
    cout << "Original array:\n";
    for(auto i: arr)
        cout << i << " ";
    
    cout << "\n\nSorted array:\n";
    sort_0s_1s_2s_optimal(arr);
    for(auto i: arr) {
        cout << i << " ";
    }
    return 0;
}