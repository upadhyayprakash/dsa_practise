#include <iostream>
#include <vector>
using namespace std;

int get_partition(vector<int> &arr, int start, int end) {
    /*
    Approach:
        1. Get the pivot
        2. Shift smaller elements to left (using pointer 'i')
        3. Shift larger elements to right (using pointer 'j')
        4. Swap pivot element with arr[j]
        5. Keep doing this until i < j
    */
    
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (i < j) {
        while(arr[i] <= pivot && i < end) {
            i++;
        }
        while(arr[j] > pivot && j > start) {
            j--;
        }
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int start, int end) {
    if(start < end) {
        int partition = get_partition(arr, start, end);
        quick_sort(arr, start, partition - 1);
        quick_sort(arr, partition + 1, end);
    }
}

int main() {
    vector<int> arr = {1,2,0,100,12,-4,9};
    cout << "Input array:" << endl;
    for(auto i: arr) {
        cout << i << " ";
    }

    quick_sort(arr, 0, arr.size()-1);

    cout << "\nSorted array:" << endl;
    for(auto i: arr) {
        cout << i << " ";
    }
    return 0;
}